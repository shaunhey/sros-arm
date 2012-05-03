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

#include "misc.h"

void _unpack(char *dest, char *src, int len)
{
        char chars[] = "0123456789ABCDEF";
        int i = 0;

        for (i = 0; i < len; i++)
        {
                int hi = (src[i] >> 4) & 0x0F;
                int lo = src[i] & 0x0F;

                dest[(i*2)  ] = chars[hi];
                dest[(i*2)+1] = chars[lo];
        }

        dest[(len*2)] = '\0';
}

void *memcpy(void *dest, void *src, size_t len)
{
	if (len > sizeof(uint32_t))
	{
		size_t chunks = len / sizeof(uint32_t);

		// block copy
		for (size_t i = 0; i < chunks; i++)
		{
			*((uint32_t *)dest+i) = *((uint32_t *)src+i);
		}

		// remainder
		if (len % sizeof(uint32_t) != 0)
		{
			for (size_t i = (chunks * sizeof(uint32_t)); i < len; i++)
			{
				*((uint8_t *)dest+i) = *((uint8_t *)src+i);
			}
		}
	}
	else
	{
		for (size_t i = 0; i < len; i++)
		{
			*((uint8_t *)dest+i) = *((uint8_t *)src+i);
		}
	}

	return dest;
}

void *memset(void *ptr, char value, size_t len)
{
	size_t i = 0;

	for (i = 0; i < len; i++)
	{
		*((char *)ptr+i) = value;
	}

	return ptr;
}
