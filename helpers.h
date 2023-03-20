#ifndef HELPERS_H
#define HELPERS_H

#include <stdint.h>
#include "vector.h"


uint8_t abs_int(int8_t x);
uint8_t add_uint(uint8_t a, int8_t b);
uint8_t clamp(uint8_t x, uint8_t min, uint8_t max);
vector_t * add_sub(uint8_t a, uint8_t sub_a, int8_t b);

#endif