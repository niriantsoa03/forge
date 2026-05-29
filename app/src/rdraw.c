#include "rdraw.h"

void    rcolor(SDL_Renderer *r, t_rgb rgb)
{
    SDL_SetRenderDrawColor(r, rgb.r, rgb.g, rgb.b, rgb.a);
}

void    draw_rpoint(SDL_Renderer *r, t_point p, t_rgb rgb)
{
    rcolor(r, rgb);
    SDL_RenderPoint(r, p.x, p.y);
}

void    draw_rline(SDL_Renderer *r, t_line line)
{
    rcolor(r, line.col);
    SDL_RenderLine(r, line.start.x, line.start.y, line.end.x, line.end.y);
}

void    draw_rlines(SDL_Renderer *r, t_line *lines, int count)
{
    int i;

    rcolor(r, lines->col);
    i = 0;
    while (i < count)
    {
        draw_rline(r, lines[i]);
        i++;
    }
    
}

void    draw_rpoints(SDL_Renderer *r, t_point *p, int count, t_rgb rgb)
{
    int i;

    i = 0;
    while (i < count)
    {
        draw_rpoint(r, p[i], rgb);
        i++;
    }
}

void    draw_rrect(SDL_Renderer *r, t_rect rect, bool hollow)
{
    SDL_FRect   rc;

    rcolor(r, rect.col);
    rc.x = rect.tlc.x;
    rc.y = rect.tlc.y;
    rc.w = rect.w;
    rc.h = rect.h;
    if (!hollow)
        SDL_RenderFillRect(r, &rc);
    else
        SDL_RenderRect(r, &rc);
}

void    draw_rrects(SDL_Renderer *r, t_rect *rects, int count, bool hollow)
{
    int i;

    i = 0;
    while (i < count)
    {
        draw_rrect(r, rects[i], hollow);
        i++;
    }
}

void    blit(SDL_Renderer *r)
{
    SDL_RenderPresent(r);
}
