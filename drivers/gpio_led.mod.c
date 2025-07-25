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
	{ 0xd9ec4b80, "gpio_to_desc" },
	{ 0x178f2652, "gpiod_set_raw_value" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xf0024008, "gpiod_direction_output_raw" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x82ee90dc, "timer_delete_sync" },
	{ 0xfe990052, "gpio_free" },
	{ 0x39ff040a, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1A4BA8AE2EAD117857F1941");
