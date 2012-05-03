/*
 * sros-arm - A research operating system for ARM systems
 * Copyright (C) 2012 Shaun R. Hey <shaun@shaunhey.com>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *  
 */

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
