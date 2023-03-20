#include <gb/gb.h>
#include <stdint.h>
#include "load_data.h"
#include "ball.h"

uint8_t main()
{

    SHOW_SPRITES;
    SHOW_BKG;

    init_bkg(0x0);
    init_win(0x0);

    load_palettes();
    load_sprites();
    load_tiles();

    ball_t *ball = ball_create();
    ball->x = 64;
    ball->y = 64;
    ball->sx = 4;
    ball->sy = -4;

    while (1)
    {
        ball_update(ball);
        ball_draw(ball);
        wait_vbl_done();
    }
}