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

#include "video.h"

// Initialize the framebuffer device
void init_video()
{
	PL110_REGS *videoRegisters = (PL110_REGS *)PL110_REGS_BASE;

	videoRegisters->LCDTiming0 = 0x3F1F3F9C;
	videoRegisters->LCDTiming1 = 0x080B61DF;
	videoRegisters->LCDTiming2 = 0x067F3800;

	videoRegisters->LCDUPBASE  = PL110_FRAMEBUFFER;
	videoRegisters->LCDControl = 0x00001829;
}

// Paint a rectangle to the framebuffer device
void paint_rect(rect r, rgba color)
{
	// Get a pointer to the framebuffer
	uint16_t *addr = (uint16_t *)PL110_FRAMEBUFFER;
	
	// Convert to RGB16
	uint16_t red_value   = (color.red   / 8);
	uint16_t blue_value  = (color.blue  / 8);
	uint16_t green_value = (color.green / 8);
	uint16_t color_value = (blue_value << 11) | (green_value << 6) | red_value;

	// Draw the rectangle (slowly)
	for (short y = r.y1; y < r.y2; y++)
	{
		for (short x = r.x1; x < r.x2; x++)
		{
			addr[(VIDEO_WIDTH*y)+x] = color_value;
		}
	}
}

// Slowly fade in and out red/green/blue
void color_cycle_demo(int count)
{
	rect r;
	r.x1 = 0;
	r.y1 = 0;
	r.x2 = VIDEO_WIDTH;
	r.y2 = VIDEO_HEIGHT;

	rgba color;

	color.red = 0;
	color.blue = 0;
	color.green = 0;

	while (count--)
	{
		for (int i = 0; i < 32; i++)
		{
			color.red = i*8;
			paint_rect(r, color); 
		}

		for (int i = 0; i < 32; i++)
		{
			color.red = 255-i*8;
			paint_rect(r, color); 
		}

		for (int i = 0; i < 32; i++)
		{
			color.green = i*8;
			paint_rect(r, color); 
		}

		for (int i = 0; i < 32; i++)
		{
			color.green = 255-i*8;
			paint_rect(r, color); 
		}

		for (int i = 0; i < 32; i++)
		{
			color.blue = i*8;
			paint_rect(r, color); 
		}

		for (int i = 0; i < 32; i++)
		{
			color.blue = 255-i*8;
			paint_rect(r, color); 
		}
	}
}

// A (poor) attempt at the SMPTE color bars
void show_color_bars()
{
	rgba color;
	rect r;

	color.red   = 180;
	color.green = 180;
	color.blue  = 180;

	r.x1 = 0;
	r.y1 = 0;
	r.x2 = VIDEO_WIDTH / 7;
	r.y2 = (VIDEO_HEIGHT / 3) * 2;

	paint_rect(r, color);


	color.red   = 180;
	color.green = 180;
	color.blue  = 16;

	r.x1 = (VIDEO_WIDTH / 7);
	r.y1 = 0;
	r.x2 = (VIDEO_WIDTH / 7) * 2;
	r.y2 = (VIDEO_HEIGHT / 3) * 2;

	paint_rect(r, color);


	color.red   = 16;
	color.green = 180;
	color.blue  = 180;

	r.x1 = (VIDEO_WIDTH / 7) * 2;
	r.y1 = 0;
	r.x2 = (VIDEO_WIDTH / 7) * 3;
	r.y2 = (VIDEO_HEIGHT / 3) * 2;

	paint_rect(r, color);

	
	color.red   = 16;
	color.green = 180;
	color.blue  = 16;

	r.x1 = (VIDEO_WIDTH / 7) * 3;
	r.y1 = 0;
	r.x2 = (VIDEO_WIDTH / 7) * 4;
	r.y2 = (VIDEO_HEIGHT / 3) * 2;

	paint_rect(r, color);


	color.red   = 180;
	color.green = 16;
	color.blue  = 180;

	r.x1 = (VIDEO_WIDTH / 7) * 4;
	r.y1 = 0;
	r.x2 = (VIDEO_WIDTH / 7) * 5;
	r.y2 = (VIDEO_HEIGHT / 3) * 2;

	paint_rect(r, color);


	color.red   = 180;
	color.green = 16;
	color.blue  = 16;

	r.x1 = (VIDEO_WIDTH / 7) * 5;
	r.y1 = 0;
	r.x2 = (VIDEO_WIDTH / 7) * 6;
	r.y2 = (VIDEO_HEIGHT / 3) * 2;

	paint_rect(r, color);


	color.red   = 16;
	color.green = 16;
	color.blue  = 180;

	r.x1 = (VIDEO_WIDTH / 7) * 6;
	r.y1 = 0;
	r.x2 = VIDEO_WIDTH;
	r.y2 = (VIDEO_HEIGHT / 3) * 2;

	paint_rect(r, color);

	// TODO:  The rest :)
}








