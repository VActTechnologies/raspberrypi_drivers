#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>

#define BUTTON_GPIO 18
static int irq_number;

static irqreturn_t button_irq_handler(int irq, void *dev_id) {
    pr_info("Button pressed!\n");
    return IRQ_HANDLED;
}

static int __init button_init(void) {
    gpio_request(BUTTON_GPIO, "button");
    gpio_direction_input(BUTTON_GPIO);
    irq_number = gpio_to_irq(BUTTON_GPIO);
    request_irq(irq_number, button_irq_handler, IRQF_TRIGGER_FALLING, "button_irq", NULL);
    return 0;
}

static void __exit button_exit(void) {
    free_irq(irq_number, NULL);
    gpio_free(BUTTON_GPIO);
}

module_init(button_init);
module_exit(button_exit);
MODULE_LICENSE("GPL");
