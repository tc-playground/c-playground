obj-m += simpleKM.o

all: build

pre:
	sudo apt install linux-headers-$$(uname -r)

load:
	sudo insmod simpleKM.ko

unload:
	sudo rmmod simpleKM.ko

build:
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules

logs:
	sudo dmesg

clean:
	make -C /lib/modules/`uname -r`/build M=$(PWD) clean
