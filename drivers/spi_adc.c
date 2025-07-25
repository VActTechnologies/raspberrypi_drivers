#include <linux/spi/spi.h>
#include <linux/module.h>

static int mcp3008_probe(struct spi_device *spi) {
    u8 tx[] = { 0x01, 0x80, 0x00 };  // Start bit, single-ended, channel 0
    u8 rx[3];

    struct spi_transfer t[] = {
        {.tx_buf = tx, .rx_buf = rx, .len = 3},
    };

    spi_sync_transfer(spi, t, 1);

    int value = ((rx[1] & 0x03) << 8) | rx[2];
    pr_info("MCP3008 ADC Value: %d\n", value);
    return 0;
}
static void mcp3008_remove(struct spi_device *spi)
{
    pr_info("MCP3008 removed\n");
}


static const struct of_device_id mcp3008_of_match[] = {
    { .compatible = "microchip,mcp3008" },
    { }
};
MODULE_DEVICE_TABLE(of, mcp3008_of_match);

static struct spi_driver mcp3008_driver = {
    .driver = {
        .name = "mcp3008",
        .of_match_table = mcp3008_of_match,
    },
    .probe = mcp3008_probe,
    .remove = mcp3008_remove,
};

module_spi_driver(mcp3008_driver);
MODULE_LICENSE("GPL");
