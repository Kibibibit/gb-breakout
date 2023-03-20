#ifndef BALL_H
#define BALL_H

#include <stdint.h>


#define BALL_WIDTH 4
#define BALL_HEIGHT 4

typedef struct {
    fixed x;
    fixed y;
    uint8_t angle;
} ball_t;

void ball_update(ball_t * ball);
void ball_draw(ball_t * ball);
ball_t * ball_create();
void ball_destroy(ball_t * ball);
void ball_collide_tile(ball_t * ball);

#endif