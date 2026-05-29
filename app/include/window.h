#ifndef WINDOW_H
# define WINDOW_H
# include "rdraw.h"
#include <stdlib.h>

/*
    STRUCT
*/

/*
    Can be later upgraded into
    typedef void (*update_callback)(t_window*, float dt, void*);
    typedef void (*render_callback)(t_window*, void*);
    typedef void (*event_callback)(t_window*, SDL_Event*, void*);
*/

typedef struct s_window
{
    SDL_Window  *whandle;
    SDL_Renderer    *ren;

    int w;
    int h;
    t_rgb bg_col;
}   t_window;

typedef void (*event_callback)(
    t_window *win,
    SDL_Event e,
    void *data
);

typedef int (*loop_callback)(
    t_window *win,
    void *data
);

t_window    *create_window(char *title, int w, int h, SDL_WindowFlags flag);
void        destroy_window(t_window *win);
void        wrun(t_window *win, loop_callback loop_fn, event_callback event_fn, void *data);
void        wblit(t_window *win);

/* APIS */
void    draw_line(t_window *win, t_line line);
void    draw_lines(t_window *win, t_line *lines, int count);
void    draw_point(t_window *win, t_point point, t_rgb col);
void    draw_points(t_window *win, t_point *points, int count, t_rgb col);
void    draw_rect(t_window *win, t_rect rect, bool hollow);
void    draw_rects(t_window *win, t_rect *rects, int count, bool hollow);
#endif
