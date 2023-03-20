#include <stdint.h>
#include <stdlib.h>
#include <gb/gb.h>
#include "ball.h"
#include "constants.h"
#include "helpers.h"
#include "trig.h"

ball_t *ball_create()
{

    ball_t *out = (ball_t *)malloc(sizeof(ball_t));
    out->x.w = 0;
    out->y.w = 0;
    out->angle = 0;

    set_sprite_tile(BALL_OAM, BALL_TILE_INDEX);
    set_sprite_prop(BALL_OAM, BALL_PALETTE);

    return out;
}
void ball_update(ball_t *ball)
{
    fixed dx,dy;
    dx = cos(ball->angle);
    dy = sin(ball->angle);

    int8_t sdx, sdy;
    sdx = cos_sign(ball->angle);
    sdy = sin_sign(ball->angle);

    fixed speed_x;
    speed_x.w  = (dx.w*2)-(dx.w/2);
    fixed speed_y;
    speed_y.w = (dy.w*2)-(dy.w/2);

    if (sdx > 0) {
        ball->x.w += speed_x.w;
    } else {
        ball->x.w -= speed_x.w;
    }
    if (sdy > 0) {
        ball->y.w += speed_y.w;
    } else {
        ball->y.w -= speed_y.w;
    }



}
void ball_draw(ball_t *ball)
{
    move_sprite(BALL_OAM, ball->x.h - 8, ball->y.h - 16);
}

void ball_destroy(ball_t *ball)
{
    move_sprite(BALL_OAM, 0, 0);
    set_sprite_tile(BALL_OAM, 0);
    set_sprite_prop(BALL_OAM, 0);
    free(ball);
}