#ifndef RDRAW_H
# define RDRAW_H
# include "struct.h"

void   rcolor(SDL_Renderer *r, t_rgb rgb);

void    draw_rpoint(SDL_Renderer *r, t_point p, t_rgb rgb);
void    draw_rpoints(SDL_Renderer *r, t_point *p, int count, t_rgb rgb);

void    draw_rline(SDL_Renderer *r, t_line line);
void    draw_rlines(SDL_Renderer *r, t_line *lines, int count);

void    draw_rrect(SDL_Renderer *r, t_rect rect, bool hollow);
void    draw_rrects(SDL_Renderer *r, t_rect *rects, int count, bool hollow);

void    blit(SDL_Renderer *r);
#endif
