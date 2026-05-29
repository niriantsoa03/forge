#include "renderer.h"

void    set_render_color(SDL_Renderer *r, t_rgb rgb)
{
    SDL_SetRenderDrawColor(r, rgb.r, rgb.g, rgb.b, rgb.a);
}

void    draw_rect(SDL_Renderer  *renderer, t_rect *rect)
{
    set_render_color(renderer, rect->col);
    SDL_FRect   r;

    r.x = rect->tlc.x;
    r.y = rect->tlc.y;
    r.w = rect->w;
    r.h = rect->h;
    SDL_RenderFillRect(renderer, &r);
}

void    init_buffer(t_rect *buff, t_rgb *col_arr)
{
    int i;
    int x;
    int y;

    i = 0;
    for (y = 0; y < 2; y++)
    {
        for (x = 0; x < 2; x++)
        {
            buff[i].col = col_arr[i];
            buff[i].w = 400;
            buff[i].h = 400;
            buff[i].tlc = (t_point){x * 400, y * 400};
            i++;
        }
    }
}

void    draw_buffer(SDL_Renderer *rend, t_rect buff[4])
{
    int i = 0;

    for (i = 0; i < 4; i++)
    {
        draw_rect(rend, buff + i);
    }
}

int    update(SDL_Renderer *rend, t_rect buff[4], t_rgb *col_arr)
{
    static uint32_t index = 0;
    int i;

    i = 0;
    for (i = 0; i < 4; i++)
    {
        buff[i].col = col_arr[(index + i) % 4];
    }
    index++;
    if (index > 100000)
        index = 0;
    draw_buffer(rend, buff);
    return (index);
}

void    draw()
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    int running;
    t_rect  buff[4];
    t_rgb col_arr[4] = {
        (t_rgb){0, 0, 0, 0},
        (t_rgb){255, 0, 0, 0},
        (t_rgb){0, 255, 0, 0},
        (t_rgb){0, 0, 255, 0},
    };

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return;
    }

    window = SDL_CreateWindow("MiniFramework", 800, 800, 0);
    if (!window) {
        printf("Window failed: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    renderer = SDL_CreateRenderer(window, NULL);

    running = 1;
    init_buffer(buff, col_arr);
    update(renderer, buff, col_arr);
    update(renderer, buff, col_arr);
    update(renderer, buff, col_arr);
    update(renderer, buff, col_arr);
    SDL_RenderPresent(renderer);

    Uint32 last;
    last = SDL_GetTicks();
    Uint32 now;
    now = last;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = 0;
            }
        }
        now = SDL_GetTicks();

        if (now - last > 1000)
        {
            last = now;
            update(renderer, buff, col_arr);
            SDL_RenderPresent(renderer);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}