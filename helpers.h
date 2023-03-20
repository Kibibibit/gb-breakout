#ifndef HELPERS_H
#define HELPERS_H

#include <stdint.h>


uint8_t abs_int(int8_t x);
uint8_t add_uint(uint8_t a, int8_t b);
uint8_t clamp(uint8_t x, uint8_t min, uint8_t max);
int8_t sign_int(int8_t x);
uint8_t uint_diff(uint8_t a, uint8_t b);
uint8_t wrap(uint8_t a, uint8_t min, uint8_t max);
uint8_t wrap_add(uint8_t a, uint8_t b, uint8_t min, uint8_t max);

#endif