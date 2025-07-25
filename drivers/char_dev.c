#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/module.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "vmem"
#define BUF_SIZE 1024

static char vmem_buf[BUF_SIZE];
static int major;
static struct cdev vmem_cdev;

static int vmem_open(struct inode *inode, struct file *file) {
    return 0;
}

static int vmem_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t vmem_read(struct file *file, char __user *buf, size_t count, loff_t *ppos) {
    return simple_read_from_buffer(buf, count, ppos, vmem_buf, BUF_SIZE);
}

static ssize_t vmem_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos) {
    return simple_write_to_buffer(vmem_buf, BUF_SIZE, ppos, buf, count);
}

static const struct file_operations vmem_fops = {
    .owner = THIS_MODULE,
    .read = vmem_read,
    .write = vmem_write,
    .open = vmem_open,
    .release = vmem_release,
};

static int __init vmem_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &vmem_fops);
    return 0;
}

static void __exit vmem_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
}

module_init(vmem_init);
module_exit(vmem_exit);
MODULE_LICENSE("GPL");
