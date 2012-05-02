#include "uart.h"
#include "misc.h"
#include "video.h"

typedef void (*puts_fn)(char *);
const puts_fn puts = uart0_puts;

int main (void)
{
	puts("Debug Console ACTIVE\n");
	puts("sros-arm 0.1\n------------\n");

	puts("Initializing video...");
	init_video();	
	puts("Done!\n");

	puts("Begin framebuffer cycle demo...");
	color_cycle_demo(1);
	puts("Done!\n");

	puts("Showing color bars...");
	show_color_bars();
	puts("Done!\n");

    return 0;
}
