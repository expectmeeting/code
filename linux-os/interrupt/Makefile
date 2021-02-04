obj-m += interrupt.o
obj-m += test.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(shell pwd) modules

clean:
	rm -rf \.module* \.tmp* *.o *.order *.symvers *.ko *.mod.c *.mod.o
