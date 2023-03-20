#include <stdint.h>
#include <stdlib.h>
#include "vector.h"

vector_t *vector_create(uint8_t x, uint8_t y)
{
    vector_t *out = (vector_t *)malloc(sizeof(vector_t));
    out->x = x;
    out->y = y;
    return out;
}
void vector_destroy(vector_t *vector)
{
    free(vector);
}