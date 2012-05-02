#ifndef MISC_H
#define MISC_H

typedef unsigned long size_t;

typedef unsigned long uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

void _unpack(char *dest, char *src, int len);

void *memcpy(void *dest, void *src, size_t len);
void *memset(void *ptr, char value, size_t len);

#endif
