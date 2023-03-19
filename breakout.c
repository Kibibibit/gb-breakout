#include <gb/gb.h>
#include <stdint.h>
#include "constants.h"
#include "object.h"
#include "load_data.h"

uint8_t main() {

    SHOW_SPRITES;
    SHOW_BKG;

    init_bkg(0x0);
    init_win(0x0);

    load_palettes();
    load_sprites();
    load_tiles();

    uint8_t  ball_refs[] = {BALL_OAM};
    uint8_t  ball_indices[] = {BALL_TILE_INDEX};
    uint8_t  ball_props[] = {BALL_PALETTE};

    object_t * ball = object_create(ball_refs, ball_indices, ball_props, 1, 0b00010001);

    object_move(ball, 8,0,8,0);
    object_show(ball);
    object_set_size(ball,4,4);


    uint8_t paddle_refs[] = {PADDLE_0_OAM, PADDLE_1_OAM, PADDLE_2_OAM};
    uint8_t paddle_indices[] = {PADDLE_EDGE_TILE_INDEX, PADDLE_MIDDLE_TILE_INDEX, PADDLE_EDGE_TILE_INDEX};
    uint8_t paddle_props[] = {PADDLE_PALETTE, PADDLE_PALETTE, PADDLE_PALETTE | SPRITE_FLIP_H};

    object_t * paddle = object_create(paddle_refs, paddle_indices, paddle_props, 3, 0b00110001);

    object_move(paddle,8,0,130,0);
    object_show(paddle);
    object_set_size(paddle,24,6);


    object_set_speed(ball, 1, 5);


    while (1) {
        object_apply_speed(ball);

        wait_vbl_done();
    }


}