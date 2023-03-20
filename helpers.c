#include <stdint.h>
#include "helpers.h"

uint8_t abs_int(int8_t x)
{
    int8_t t = x >> 7;
    return (uint8_t)((x ^ t) - t);
}

uint8_t add_uint(uint8_t a, int8_t b)
{
    if (b < 0)
    {
        if (abs_int(b) > a)
        {
            return 0;
        }
        else
        {
            return a + b;
        }
    }
    else
    {
        uint16_t x = a + b;
        if (x > 0xFF)
        {
            return 0xFF;
        }
        else
        {
            return a + b;
        }
    }
}

int8_t sign_int(int8_t x)
{
    if (x == 0)
    {
        return 0;
    }
    if ((0b10000000 & x) != 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

uint8_t clamp(uint8_t x, uint8_t min, uint8_t max)
{
    if (x < min)
    {
        return min;
    }
    if (x > max)
    {
        return max;
    }
    return x;
}

uint8_t uint_diff(uint8_t a, uint8_t b)
{
    uint8_t x, y;
    if (a < b)
    {
        x = a;
        y = b;
    }
    else
    {
        x = b;
        y = a;
    }
    return y - x;
}

uint8_t wrap(uint8_t a, uint8_t min, uint8_t max)
{
   uint8_t diff = max-min;
   uint8_t m = (a-min) % diff;
   return m+min;
}
