#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/timer.h>

#define LED_GPIO 17  // BCM GPIO number

static struct timer_list blink_timer;
static bool led_on = false;

static void blink_timer_func(struct timer_list *t) {
    led_on = !led_on;
    gpio_set_value(LED_GPIO, led_on);
    mod_timer(&blink_timer, jiffies + msecs_to_jiffies(500));
}

static int __init led_init(void) {
    gpio_request(LED_GPIO, "LED");
    gpio_direction_output(LED_GPIO, 0);
    timer_setup(&blink_timer, blink_timer_func, 0);
    mod_timer(&blink_timer, jiffies + msecs_to_jiffies(500));
    return 0;
}

static void __exit led_exit(void) {
    del_timer_sync(&blink_timer);
    gpio_set_value(LED_GPIO, 0);
    gpio_free(LED_GPIO);
}

module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
