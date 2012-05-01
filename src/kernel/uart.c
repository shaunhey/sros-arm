#include "uart.h"

void uart0_putc(char c)
{
	// Wait for the output buffer to clear
	while (*(volatile unsigned long *)UART0_FR & UART_BUFFER_FULL);

	// Actually write the byte
	*(volatile unsigned long *)UART0_BASE = c; 
}

void uart0_puts(char *s)
{
	// Write characters one at a time until we hit a null
	while (*s) { uart0_putc(*s++); }

	uart0_putc('\n');
}
