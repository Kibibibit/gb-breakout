#include <stdlib.h>
#include <stdint.h>
#include <gb/gb.h>
#include "object.h"

object_t * object_create(uint8_t * oam_refs, uint8_t * sprite_indices, uint8_t * sprite_props, uint8_t sprite_count, uint8_t sprite_layout) {

    object_t * object = (object_t *)malloc(sizeof(object_t));

    object->oam_refs = (uint8_t *)malloc(sprite_count*sizeof(uint8_t));
    object->sprite_props = (uint8_t *)malloc(sprite_count*sizeof(uint8_t));
    object->sprite_indices = (uint8_t *)malloc(sprite_count*sizeof(uint8_t));

    object->oam_refs = oam_refs;
    object->sprite_props = sprite_props;
    object->sprite_count = sprite_count;
    object->sprite_indices = sprite_indices;
    object->extra_data = OBJECT_HIDDEN;
    object->sprite_layout = sprite_layout;

    object->w = 0;
    object->h = 0;
    object->x = 0;
    object->y = 0;
    object->sub_x = 0;
    object->sub_y = 0;
    object->dx = 0;
    object->dy = 0;

    uint8_t i;
    
    for (i = 0; i < sprite_count; i++ ) {
        set_sprite_tile(oam_refs[i], sprite_indices[i]);
        set_sprite_prop(oam_refs[i], sprite_props[i]);
    }

    return object;
}

void object_set_size(object_t * object, uint8_t w, uint8_t h) {
    object->w = w;
    object->h = h;
}
void object_move(object_t * object, uint8_t x, int8_t sub_x, uint8_t y, int8_t sub_y){
    object->x = x;
    object->y = y;
    object->sub_x = sub_x;
    object->sub_y = sub_y;
    object_update(object);
}

void object_set_speed(object_t * object, uint8_t dx, uint8_t dy)
{
    object->dx = dx;
    object->dy = dy;
}

void object_hide(object_t * object){
    object->extra_data = object->extra_data | OBJECT_SET_HIDDEN;
    uint8_t i;
    for (i = 0; i < object->sprite_count; i++) {
        move_sprite(object->oam_refs[i],0,0);
    }
}
void object_show(object_t * object){
    object->extra_data = object->extra_data & OBJECT_SET_VISIBLE;
    object_update(object);
}

uint8_t object_is_hidden(object_t * object) {
    return (object->extra_data & OBJECT_HIDDEN) > 0;
}

void object_destroy(object_t * object) {

    uint8_t i;
    
    for (i = 0; i < object->sprite_count; i++) {
        set_sprite_tile(object->oam_refs[i], 0x0);
        set_sprite_prop(object->oam_refs[i], 0x0);
        move_sprite(object->oam_refs[i],0,0);
    }

    free(object->oam_refs);
    free(object->sprite_props);
    free(object->sprite_indices);
    free(object);
}

uint8_t object_get_rows(object_t * object) {
    return object->sprite_layout & OBJECT_SPRITE_ROWS;
}
uint8_t object_get_cols(object_t * object) {
    return (object->sprite_layout & OBJECT_SPRITE_COLS) >> 4;
}

void object_update(object_t * object) {
    if (!object_is_hidden(object)) {
        uint8_t i = 0;
        uint8_t x,y;
        for (x = 0; x < object_get_cols(object); x++) 
        {
            for (y = 0; y < object_get_rows(object); y++)
            {
                move_sprite(object->oam_refs[i],object->x+(x*8), object->y+8+(y*8));
                i++;
                if (i >= object->sprite_count) {
                    return;
                }
            }
        }
    }
}

void object_apply_speed(object_t * object) {


    uint8_t i;

    for (i = 0; i < object->dx; i++) {

        if (object->sub_x < 10 && object->sub_x >= 0) {
            object->sub_x += abs(object->dx);
        } else if (object->sub_x < 0) {
            object->sub_x = 9;
            object->x--;
        } else if (object->sub_x >= 10) {
            object->sub_x = 0;
            object->x++;
        }

    }

    for (i = 0; i < object->dy; i++) {

        if (object->sub_y < 10 && object->sub_y >= 0) {
            object->sub_y += abs(object->dy);
        } else if (object->sub_y < 0) {
            object->sub_y = 9;
            object->y--;
        } else if (object->sub_y >= 10) {
            object->sub_y = 0;
            object->y++;
        }

    }

    object_update(object);

}

