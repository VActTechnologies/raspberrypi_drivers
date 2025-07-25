#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xeb081dc5, "i2c_register_driver" },
	{ 0x5151c2fc, "sysfs_remove_group" },
	{ 0xd41cd16a, "_dev_info" },
	{ 0x6c175b74, "i2c_smbus_read_word_data" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x122c3a7e, "_printk" },
	{ 0x8950dd19, "sysfs_create_group" },
	{ 0x5b08cec9, "i2c_del_driver" },
	{ 0x39ff040a, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:lm75");

MODULE_INFO(srcversion, "F5F28B04BB8CFF98CE54934");
