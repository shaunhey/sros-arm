ODIR = ./obj
SDIR = ./src
OBJS = $(ODIR)/start.o $(ODIR)/main.o $(ODIR)/uart.o $(ODIR)/misc.o
CC = arm-elf-gcc
CFLAGS = -Wall -Wextra -Werror -nostdlib -nostartfiles -ffreestanding -std=gnu99 -c
INCLUDE = ./include
DEPS = $(INCLUDE)/%.h

all: bin/kernel

$(ODIR)/start.o: $(SDIR)/kernel/start.s
	arm-elf-as -o $(ODIR)/start.o $(SDIR)/kernel/start.s

$(ODIR)/main.o: $(SDIR)/kernel/main.c
	$(CC) $(CFLAGS) $(SDIR)/kernel/main.c -o $(ODIR)/main.o -I$(INCLUDE)

$(ODIR)/uart.o: $(SDIR)/kernel/uart.c
	$(CC) $(CFLAGS) $(SDIR)/kernel/uart.c -o $(ODIR)/uart.o -I$(INCLUDE)

$(ODIR)/misc.o: $(SDIR)/kernel/misc.c
	$(CC) $(CFLAGS) $(SDIR)/kernel/misc.c -o $(ODIR)/misc.o -I$(INCLUDE)

bin/kernel: $(OBJS)
	arm-elf-ld -T $(SDIR)/kernel/link.ld -o bin/kernel $(OBJS)

.PHONY: clean

clean:
	rm -f *~ $(ODIR)/*.o $(INCLUDE)/*~ $(SRC)/*~ bin/kernel
