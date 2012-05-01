#ifndef UART_H
#define UART_H

#define	UART0_BASE			0x16000000
#define	UART0_SR			(UART0_BASE + 0x00000004)
#define	UART0_FR			(UART0_BASE + 0x00000018)

#define	UART_BUFFER_FULL	(1<<5)

void uart0_puts(char *s);
void uart0_putc(char c);

#endif
