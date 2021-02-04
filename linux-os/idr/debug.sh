#!/bin/bash

modname=idr.ko

insmod ${modname}
rmmod ${modname}
dmesg -c
