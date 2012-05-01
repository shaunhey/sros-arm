#include "uart.h"
#include "misc.h"

typedef void (*puts_fn)(char *);
puts_fn puts;

void init()
{
	puts = uart0_puts;
}

int main (void)
{
	char szTest[8] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF};
	char szUnpacked[17] = {0};
	init();
    puts("sros-arm booting...");
	_unpack(szUnpacked, szTest, 8);
	puts(szUnpacked);

	
    return 0;
}
