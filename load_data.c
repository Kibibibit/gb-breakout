#include <gb/gb.h>
#include <gb/cgb.h>
#include "load_data.h"
#include "constants.h"
#include "sprites.h"

void load_sprites() {

    set_sprite_data(BALL_TILE_INDEX,1,spritesTLE0);
    set_sprite_data(PADDLE_EDGE_TILE_INDEX,1,spritesTLE1);
    set_sprite_data(PADDLE_MIDDLE_TILE_INDEX,1,spritesTLE2);

}

void load_palettes() {
    palette_color_t palette_0[] = {spritesCGBPal0c0, spritesCGBPal0c1, spritesCGBPal0c2, spritesCGBPal0c3};
    palette_color_t palette_1[] = {spritesCGBPal1c1, spritesCGBPal1c1, spritesCGBPal1c2, spritesCGBPal1c3};
    set_sprite_palette(BALL_PALETTE,1,palette_0);
    set_sprite_palette(PADDLE_PALETTE,1,palette_1);

}
void load_tiles() {

}