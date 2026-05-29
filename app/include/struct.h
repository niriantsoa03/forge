#ifndef STRUCT_H
# define STRUCT_H
#include <SDL3/SDL.h>

/*
    Contains enum and structure definition
*/

typedef uint8_t byte;

typedef struct s_rgb
{
    byte    r;
    byte    g;
    byte    b;
    byte    a;
}   t_rgb;


typedef struct  s_point
{
    int32_t x;
    int32_t y;
}   t_point;


typedef struct s_rect
{
    uint32_t w;
    uint32_t h;
    t_point tlc;
    t_rgb   col;
}   t_rect;

#endif
