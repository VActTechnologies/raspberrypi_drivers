#include <linux/tty.h>
#include <linux/tty_driver.h>
#include <linux/module.h>
#include <linux/serial_core.h>
#include <linux/platform_device.h>
#include <linux/of.h>


static int gps_uart_probe(struct platform_device *pdev) {
    pr_info("UART GPS module probed\n");
    return 0;
}

static void gps_uart_remove(struct platform_device *pdev) {
    pr_info("UART GPS module removed\n");
    
}

static const struct of_device_id gps_of_match[] = {
    { .compatible = "josith,gps-uart" },
    { }
};
MODULE_DEVICE_TABLE(of, gps_of_match);

static struct platform_driver gps_uart_driver = {
    .driver = {
        .name = "gps_uart",
        .of_match_table = gps_of_match,
    },
    .probe = gps_uart_probe,
    .remove = gps_uart_remove,
};

module_platform_driver(gps_uart_driver);
MODULE_LICENSE("GPL");
