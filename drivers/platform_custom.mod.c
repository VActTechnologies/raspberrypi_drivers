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
	{ 0xf970cbeb, "__platform_driver_register" },
	{ 0x122c3a7e, "_printk" },
	{ 0x25e47ffd, "platform_driver_unregister" },
	{ 0x39ff040a, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cjosith,customdev");
MODULE_ALIAS("of:N*T*Cjosith,customdevC*");

MODULE_INFO(srcversion, "6BEC273AB64948F76F15FDA");
