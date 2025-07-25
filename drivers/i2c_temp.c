#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DRIVER_NAME "lm75_custom"

// Replace this with actual register address if different
#define LM75_TEMP_REG 0x00

static struct i2c_client *lm75_client;

static int lm75_read_temperature(void)
{
    s16 temp;
    int ret;

    // Read 2 bytes from temperature register
    ret = i2c_smbus_read_word_data(lm75_client, LM75_TEMP_REG);
    if (ret < 0) {
        pr_err(DRIVER_NAME ": Failed to read temperature\n");
        return ret;
    }

    // LM75 data is big-endian: swap bytes
    temp = (ret << 8) | (ret >> 8);
    
    // Temperature is in 0.125°C steps (LM75 format)
    return temp >> 5;
}

static ssize_t temp_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int temp = lm75_read_temperature();
    if (temp < 0)
        return temp;
    return sprintf(buf, "%d\n", temp);
}

static DEVICE_ATTR_RO(temp);

static struct attribute *lm75_attrs[] = {
    &dev_attr_temp.attr,
    NULL,
};

static const struct attribute_group lm75_attr_group = {
    .attrs = lm75_attrs,
};

static int lm75_probe(struct i2c_client *client)
{
    lm75_client = client;
    dev_info(&client->dev, "LM75 temperature sensor probed\n");

    return sysfs_create_group(&client->dev.kobj, &lm75_attr_group);
}

static void lm75_remove(struct i2c_client *client)
{
    sysfs_remove_group(&client->dev.kobj, &lm75_attr_group);
    dev_info(&client->dev, "LM75 temperature sensor removed\n");
}

static const struct i2c_device_id lm75_id[] = {
    { "lm75", 0 },
    { }
};
MODULE_DEVICE_TABLE(i2c, lm75_id);

static struct i2c_driver lm75_driver = {
    .driver = {
        .name = DRIVER_NAME,
    },
    .probe = lm75_probe,

    .remove = lm75_remove,
    .id_table = lm75_id,
};

module_i2c_driver(lm75_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Josith Ganesan");
MODULE_DESCRIPTION("LM75 Temperature Sensor Driver");
