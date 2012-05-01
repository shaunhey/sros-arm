#include "misc.h"

void _unpack(char *dest, char *src, int len)
{
        char chars[] = "0123456789ABCDEF";
        int i = 0;

        for (i = 0; i < len; i++)
        {
                char hi = (src[i] >> 4) & 0x0F;
                char lo = src[i] & 0x0F;

                dest[(i*2)  ] = chars[hi];
                dest[(i*2)+1] = chars[lo];
        }

        dest[(len*2)] = '\0';
}

