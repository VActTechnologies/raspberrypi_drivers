obj-m += gpio_led.o
obj-m += button_irq.o
obj-m += char_dev.o
obj-m += platform_custom.o
obj-m += i2c_temp.o
obj-m += spi_adc.o
obj-m += uart_gps.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
