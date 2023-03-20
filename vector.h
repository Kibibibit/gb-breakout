#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>

typedef struct {
    uint8_t x;
    uint8_t y;
} vector_t;

vector_t * vector_create(uint8_t x, uint8_t y);
void vector_destroy(vector_t * vector);


#endif