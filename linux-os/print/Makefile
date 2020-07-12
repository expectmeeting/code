obj-m += module-pattern.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(shell pwd) modules

loop:
	$(shell insmod module-pattern.ko)
	$(shell sleep 1)
	$(shell rmmod module-pattern)

clean:
	rm -rf \.module* \.tmp* *.o *.order *.symvers *.ko *.mod.c *.mod.o
