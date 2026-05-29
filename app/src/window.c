#include "window.h"

t_window    *create_window(char *title, int w, int h, SDL_WindowFlags flag)
{
    t_window    *win;

    win = (t_window *)malloc(sizeof(t_window));

    if (!win)
        return (NULL);
    win->w = w;
    win->h = h;
    win->whandle = SDL_CreateWindow(title, w, h, flag);
    if (!win->whandle)
    {
        free(win);
        return (NULL);
    }
    win->ren = SDL_CreateRenderer(win->whandle, NULL);
    if (!win->ren)
    {
        SDL_DestroyWindow(win->whandle);
        free(win);
        return (NULL);
    }
    return (win);
}

void        destroy_window(t_window *win)
{
    SDL_DestroyRenderer(win->ren);
    SDL_DestroyWindow(win->whandle);
    free(win);
}

void    wblit(t_window *win)
{
    blit(win->ren);
}

void        wrun(t_window *win, loop_callback loop_fn, event_callback event_fn, void *data)
{
    int loop;
    SDL_Event   e;

    loop = 1;
    while (loop)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_EVENT_QUIT)
                return ;
            if (event_fn)
                event_fn(win, e, data);
        }
        if (loop_fn)
            loop = loop_fn(win, data);
        /*
            wblit(win);
        */
    }
}

/*API*/
void draw_line(t_window *win, t_line line)
{
    if (!win)
        return;
    draw_rline(win->ren, line);
}

void draw_lines(t_window *win, t_line *lines, int count)
{
    if (!win || !lines || count <= 0)
        return;
    draw_rlines(win->ren, lines, count);
}

void draw_point(t_window *win, t_point point, t_rgb col)
{
    if (!win)
        return;
    draw_rpoint(win->ren, point, col);
}

void draw_points(t_window *win, t_point *points, int count, t_rgb col)
{
    if (!win || !points || count <= 0)
        return;
    draw_rpoints(win->ren, points, count, col);
}

void draw_rect(t_window *win, t_rect rect, bool hollow)
{
    if (!win)
        return;
    draw_rrect(win->ren, rect, hollow);
}

void draw_rects(t_window *win, t_rect *rects, int count, bool hollow)
{
    if (!win || !rects || count <= 0)
        return;
    draw_rrects(win->ren, rects, count, hollow);
}
