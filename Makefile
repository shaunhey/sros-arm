
# sros-arm - A research operating system for ARM systems
# Copyright (C) 2012 Shaun R. Hey <shaun@shaunhey.com>
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

OBJS = 	obj/start.o \
		obj/main.o 	\
		obj/uart.o 	\
		obj/misc.o 	\
		obj/video.o \
		obj/sd.o

CC = arm-elf-gcc
CFLAGS = -Wall -Wextra -Werror -nostdlib -nostartfiles -ffreestanding -std=gnu99 -c

all: bin/kernel

obj/start.o: src/kernel/start.s
	arm-elf-as -o obj/start.o src/kernel/start.s

obj/%.o: src/kernel/%.c
	$(CC) $(CFLAGS) $< -o $@ -Iinclude

bin/kernel: $(OBJS)
	arm-elf-ld -T src/kernel/link.ld -o bin/kernel $(OBJS)

.PHONY: clean

clean:
	rm -f *~ obj/*.o include/*~ src/*~ bin/kernel
