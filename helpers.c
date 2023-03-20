#include <stdint.h>
#include "helpers.h"
#include "vector.h"

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

vector_t * add_sub(uint8_t a, uint8_t sub_a, int8_t b)
{
    uint8_t new_sub = sub_a;
    uint8_t new_a = a;

    uint8_t i;
    for (i = 0; i < abs_int(b); i++) {

        if (b < 0) {
            if (new_sub == 0) {
                new_sub = 9;
                new_a -= 1;
            } else {
                new_sub-=1;
            }
        } else {
            if (new_sub == 9) {
                new_sub = 0;
                new_a += 1;
            } else {
                new_sub+=1;
            }
        }

    }

    return vector_create(new_a, new_sub);
}