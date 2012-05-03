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
}
