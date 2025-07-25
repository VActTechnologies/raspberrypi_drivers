# raspberrypi_drivers
#  Raspberry Pi Linux Kernel Drivers (All-in-One)
This repository contains multiple Linux kernel modules written and tested on Raspberry Pi. Each module demonstrates key aspects of Linux device driver development — including GPIO, interrupts, character devices, and interfacing with external hardware via I2C, SPI, and UART.

---

##  Included Modules

| File              | Description                                          |
|-------------------|------------------------------------------------------|
| `gpio_led.c`       | GPIO output control (LED blink)                     |
| `button_irq.c`     | GPIO button interrupt handling                      |
| `char_dev.c`       | Character device (e.g., `/dev/char_device`)         |
| `platform_custom.c`| Registers platform devices for I2C, SPI, UART       |
| `i2c_temp.c`       | I2C temperature sensor (e.g., LM75/DS1621)          |
| `spi_adc.c`        | SPI ADC interface (e.g., MCP3008)                   |
| `uart_gps.c`       | UART driver for GPS module                          |
| `Makefile`         | Unified Makefile to build all modules               |

---

##  Requirements

- Raspberry Pi (with 40-pin GPIO)
- Linux kernel 6.x
- Kernel headers installed

Install headers (if not already):

```bash
sudo apt install raspberrypi-kernel-headers
```
##  Build Instructions

In the directory containing all the `.c` files and `Makefile`, run:
```
make
```
This will compile all modules and generate `.ko` files.

---

##  Load All Modules

Ensure you load the platform driver first (since others rely on it):
```
sudo insmod platform_custom.ko
sudo insmod gpio_led.ko
sudo insmod button_irq.ko
sudo insmod char_dev.ko
sudo insmod i2c_temp.ko
sudo insmod spi_adc.ko
sudo insmod uart_gps.ko

```

Verify using:
```
dmesg | tail
```

##  Unload All Modules

To remove all drivers:
```
sudo rmmod uart_gps
sudo rmmod spi_adc
sudo rmmod i2c_temp
sudo rmmod char_dev
sudo rmmod button_irq
sudo rmmod gpio_led
sudo rmmod platform_custom

```

# Thank you 
