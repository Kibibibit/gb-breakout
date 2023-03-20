#ifndef PADDLE_H
#define PADDLE_H

#include <stdint.h>

#define PADDLE_WIDTH 24
#define PADDLE_HEIGHT 6
#define PADDLE_Y 140
#define PADDLE_MIN_X 8
#define PADDLE_MAX_X 140

typedef uint8_t paddle_t;
paddle_t paddle_create();
void paddle_draw(paddle_t paddle);
paddle_t paddle_update(paddle_t paddle, uint8_t input);
void paddle_destroy();


#endif