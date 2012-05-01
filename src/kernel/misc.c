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
	size_t i = 0;

	for (i = 0; i < len; i++)
	{
		*((char *)dest+i) = *((char *)src+i);
	}

	return dest;
}
