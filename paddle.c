#include <stdint.h>
#include <gb/gb.h>
#include <stdlib.h>
#include "constants.h"
#include "paddle.h"
#include "helpers.h"

paddle_t paddle_create()
{
    return 8;
}
void paddle_draw(paddle_t paddle)
{
    move_sprite(PADDLE_0_OAM, paddle-8,PADDLE_Y);
    move_sprite(PADDLE_1_OAM, paddle, PADDLE_Y);
    move_sprite(PADDLE_2_OAM, paddle+8, PADDLE_Y);
}
paddle_t paddle_update(paddle_t paddle, uint8_t input)
{
    paddle_t out = paddle;
    if ((input & J_LEFT) > 0) {
        out = add_uint(out, -1);
    }
    if ((input & J_RIGHT) > 0) {
        out = add_uint(out, 1);
    }
    return clamp(out,PADDLE_MIN_X,PADDLE_MAX_X);

}
void paddle_destroy()
{
    move_sprite(PADDLE_0_OAM, 0,0);
    move_sprite(PADDLE_1_OAM, 0,0);
    move_sprite(PADDLE_2_OAM, 0,0);
}