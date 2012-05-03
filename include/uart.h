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

#ifndef UART_H
#define UART_H

#define	UART0_BASE			0x16000000
#define	UART0_SR			(UART0_BASE + 0x00000004)
#define	UART0_FR			(UART0_BASE + 0x00000018)

#define	UART_BUFFER_FULL	(1<<5)

void uart0_puts(char *s);
void uart0_putc(char c);

#endif
