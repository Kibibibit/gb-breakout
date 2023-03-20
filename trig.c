#include <stdint.h>
#include <gb/gb.h>
#include "trig.h"
#include "helpers.h"


const uint8_t angle_table_h[] = {0,0,0,0,0,0,1,0,0,0,0,0};
const uint8_t angle_table_l[] = {0,77,128,179,204,230,0,230,204,179,128,77};

fixed sin(uint8_t x)
{
    uint8_t i = wrap(x, 0, 12);
    fixed out;
    out.h=angle_table_h[i];
    out.l=angle_table_l[i];
    return out;
}

fixed cos(uint8_t x)
{
    uint8_t i = wrap(x+DEG_90, 0, 12);
    fixed out;
    out.h=angle_table_h[i];
    out.l=angle_table_l[i];
    return out;
}

int8_t sin_sign(uint8_t x)
{
    uint8_t i = wrap(x, 0, 24);

    if (i < 12)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int8_t cos_sign(uint8_t x)
{
    return sin_sign(x+DEG_90);
}
