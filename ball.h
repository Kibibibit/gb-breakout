#ifndef BALL_H
#define BALL_H

#include <stdint.h>
#include "vector.h"


#define BALL_WIDTH 4
#define BALL_HEIGHT 4


typedef struct {
    uint8_t x;
    uint8_t y;
    int8_t sub_x;
    int8_t sub_y;
    int8_t sx;
    int8_t sy;
} ball_t;

void ball_update(ball_t * ball);
void ball_draw(ball_t * ball);
ball_t * ball_create();
void ball_destroy(ball_t * ball);

#endif