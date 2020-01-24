obj-m += simple-km-01.o

TARGET=simple-km-01.ko

# https://unix.stackexchange.com/questions/543576/modprobe-fails-with-permission-denied
# 
# sudo su root
#	echo 1 > /proc/sys/kernel/sysrq
#	echo x > /proc/sysrq-trigger
#	exit

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

info:
	@modinfo $(TARGET)

load:
	@sudo insmod ./$(TARGET)

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
