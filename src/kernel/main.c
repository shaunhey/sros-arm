#include "uart.h"

typedef void (*puts_fn)(char *);
puts_fn puts;

void init()
{
	puts = uart0_puts;
}

int main (void)
{
	init();
    puts("sros-arm booting...\n");
    return 0;
}
