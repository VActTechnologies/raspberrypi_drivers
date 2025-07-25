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
	{ 0xcec1d106, "__spi_register_driver" },
	{ 0x122c3a7e, "_printk" },
	{ 0xd51bf3d7, "driver_unregister" },
	{ 0xdcb764ad, "memset" },
	{ 0x3364cb49, "spi_sync" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x39ff040a, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cmicrochip,mcp3008");
MODULE_ALIAS("of:N*T*Cmicrochip,mcp3008C*");

MODULE_INFO(srcversion, "2AF0A5D117130A24022866C");
