#include "window.h"
#include <stdio.h>

typedef struct s_data
{
    uint32_t    last_ticks;
    int         count;
}   t_data;

void    event_handler(t_window *win, SDL_Event e, void *data)
{
    (void) data;
    (void) win;
    printf("An event occured: %d\n", e.type);
}

int    loop_handler(t_window *win, void *data)
{
    t_data  *dt;
    uint32_t    now;

    (void) win;
    dt = (t_data*) data;
    if (!dt)
        return (0);
    now = SDL_GetTicks();
    if (now - dt->last_ticks > 1000)
    {
        dt->count++;
        dt->last_ticks = now;
        printf("Counter value: %d\n", dt->count);
    }
    return (dt->count < 10);
}

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    t_window    *win;
    t_data  data;

    win = create_window("bye bye", 700, 700, 0);
    if (!win)
    {
        printf("Something went wrong...\n");
        return (1);
    }
    data.count = 0;
    data.last_ticks = SDL_GetTicks();
    draw_rline(
        win->ren,
        (t_line){
            (t_point){0, 0},
            (t_point){700, 700},
            (t_rgb){255, 0, 0, 0},
        }
    );
    draw_rrect(
        win->ren,
        (t_rect){
            200,
            200,
            (t_point){33, 50},
            (t_rgb){0, 255, 0, 255}
        },
        false
    );
    wblit(win);
    wrun(win, NULL, NULL, &data);
    destroy_window(win);
    return 0;
}
