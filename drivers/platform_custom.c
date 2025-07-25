#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of.h>


static int custom_probe(struct platform_device *pdev) {
    pr_info("Custom platform device probed\n");
    return 0;
}
static void custom_remove(struct platform_device *pdev)
{
    printk(KERN_INFO "Custom platform device removed\n");
}


static const struct of_device_id custom_of_match[] = {
    { .compatible = "josith,customdev", },
    { },
};
MODULE_DEVICE_TABLE(of, custom_of_match);

static struct platform_driver custom_driver = {
    .probe = custom_probe,
    .remove = custom_remove,
    .driver = {
        .name = "customdev",
        .of_match_table = custom_of_match,
    },
};

module_platform_driver(custom_driver);
MODULE_LICENSE("GPL");
