#ifndef OBJECT_H
#define OBJECT_H

#include <stdint.h>

#define OBJECT_HIDDEN 0b10000000
#define OBJECT_SET_HIDDEN  0b10000000
#define OBJECT_SET_VISIBLE 0b01111111

#define OBJECT_SPRITE_COLS 0b11110000
#define OBJECT_SPRITE_ROWS 0b00001111

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t dx;
    uint8_t dy;
    int8_t sub_x;
    int8_t sub_y;
    uint8_t w;
    uint8_t h;
    uint8_t sprite_layout;
    uint8_t extra_data;
    uint8_t sprite_count;
    uint8_t * oam_refs;
    uint8_t * sprite_indices;
    uint8_t * sprite_props;
} object_t;

object_t * object_create(uint8_t * oam_refs, uint8_t * sprite_indices, uint8_t * sprite_props, uint8_t sprite_count, uint8_t sprite_layout);
void object_set_size(object_t * object, uint8_t w, uint8_t h);
void object_set_speed(object_t * object, uint8_t dx, uint8_t dy);
void object_move(object_t * object, uint8_t x, int8_t sub_x, uint8_t y, int8_t sub_y);
void object_hide(object_t * object);
void object_show(object_t * object);
uint8_t object_is_hidden(object_t * object);
void object_destroy(object_t * object);
void object_update(object_t * object);
uint8_t object_get_rows(object_t * object);
uint8_t object_get_cols(object_t * object);
void object_apply_speed(object_t * object);


#endif