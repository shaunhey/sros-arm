#!/bin/bash

make

if [ $? -ne 0 ]
then
	exit 1
fi

qemu-system-arm -m 128 -kernel bin/kernel -serial stdio

