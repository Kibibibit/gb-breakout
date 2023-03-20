#ifndef TRIG_H
#define TRIG_H
#include <stdint.h>
#include <gb/gb.h>

#define DEG_0 0
#define DEG_15 1
#define DEG_30 2
#define DEG_45 3
#define DEG_60 4
#define DEG_75 5
#define DEG_90 6
#define DEG_105 7
#define DEG_120 8
#define DEG_135 9
#define DEG_150 10
#define DEG_165 11
#define DEG_180 12
#define DEG_195 13
#define DEG_210 14
#define DEG_225 15
#define DEG_240 16
#define DEG_255 17
#define DEG_270 18
#define DEG_285 19
#define DEG_300 20
#define DEG_315 21
#define DEG_330 22
#define DEG_345 23
#define DEG_360 0

extern const uint8_t angle_table_h[];
extern const uint8_t angle_table_l[];

fixed sin(uint8_t x);
fixed cos(uint8_t x);
int8_t sin_sign(uint8_t x);
int8_t cos_sign(uint8_t x);


#endif