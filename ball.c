#include <stdint.h>
#include <stdlib.h>
#include <gb/gb.h>
#include "ball.h"
#include "constants.h"
#include "vector.h"
#include "helpers.h"

ball_t *ball_create()
{

    ball_t *out = (ball_t *)malloc(sizeof(ball_t));
    out->x = 0;
    out->y = 0;
    out->sub_x = 0;
    out->sub_y = 0;
    out->sx = 0;
    out->sy = 0;

    set_sprite_tile(BALL_OAM, BALL_TILE_INDEX);
    set_sprite_prop(BALL_OAM, BALL_PALETTE);

    return out;
}
void ball_update(ball_t *ball)
{
    vector_t *x_vector = add_sub(ball->x, ball->sub_x, ball->sx);
    vector_t *y_vector = add_sub(ball->y, ball->sub_y, ball->sy);

    uint8_t new_x = x_vector->x;
    uint8_t new_sub_x = x_vector->y;
    uint8_t new_y = y_vector->x;
    uint8_t new_sub_y = y_vector->y;

    free(x_vector);
    free(y_vector);

    ball->x = new_x;
    ball->y = new_y;
    ball->sub_x = new_sub_x;
    ball->sub_y = new_sub_y;
}
void ball_draw(ball_t *ball)
{
    move_sprite(BALL_OAM, ball->x - 8, ball->y - 16);
}

void ball_destroy(ball_t *ball)
{
    move_sprite(BALL_OAM, 0, 0);
    set_sprite_tile(BALL_OAM, 0);
    set_sprite_prop(BALL_OAM, 0);
    free(ball);
}