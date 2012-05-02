#ifndef VIDEO_H
#define VIDEO_H

#include "misc.h"

#define PL110_REGS_BASE		0xC0000000
#define	PL110_FRAMEBUFFER	0x00200000

#define VIDEO_WIDTH			640
#define VIDEO_HEIGHT		480

typedef struct 
{
	volatile uint32_t LCDTiming0;
	volatile uint32_t LCDTiming1;
	volatile uint32_t LCDTiming2;
	volatile uint32_t LCDTiming3;
	volatile uint32_t LCDUPBASE;
	volatile uint32_t LCDLPBASE;
	volatile uint32_t LCDINTRENABLE;
	volatile uint32_t LCDControl;
	volatile uint32_t LCDStatus;
	volatile uint32_t LCDInterrupt;
	volatile uint32_t LCDUPCURR;
	volatile uint32_t LCDLPCURR;
} PL110_REGS;

typedef struct
{
	uint16_t x1;
	uint16_t y1;
	uint16_t x2;
	uint16_t y2;
} rect;

typedef struct 
{
	unsigned char red;
	unsigned char blue;
	unsigned char green;
	unsigned char alpha;
} rgba;

void init_video();
void paint_rect(rect r, rgba color);
void color_cycle_demo(int count);
void show_color_bars();

#endif
