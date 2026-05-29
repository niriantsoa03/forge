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
    double x;
    double y;
}   t_point;


typedef struct s_rect
{
    uint32_t w;
    uint32_t h;
    t_point tlc;
    t_rgb   col;
}   t_rect;

typedef struct s_line
{
    t_point start;
    t_point end;
    t_rgb   col;
}   t_line;

#endif
