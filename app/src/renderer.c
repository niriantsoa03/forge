#include "renderer.h"


void    draw()
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    int running;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return;
    }

    window = SDL_CreateWindow("MiniFramework", 800, 600, 0);
    if (!window) {
        printf("Window failed: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    renderer = SDL_CreateRenderer(window, NULL);

    running = 1;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = 0;
            }
        }

        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        {
            SDL_FRect rect;
            rect.x = 100.0f;
            rect.y = 100.0f;
            rect.w = 200.0f;
            rect.h = 150.0f;

            SDL_RenderFillRect(renderer, &rect);
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}