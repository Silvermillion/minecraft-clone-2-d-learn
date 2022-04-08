#include <SDL2/SDL.h>
#include <window/window.h>

#define WIDTH 640
#define HEIGHT 480

static SDL_Window *g_window = NULL;
static SDL_Surface *g_win_surface;

void create_window() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr, "Error: Could not initialize SDL, %s\n",
                SDL_GetError());
        exit(-1);
    }
    g_window = SDL_CreateWindow("2D Minecraft", SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
                                SDL_WINDOW_SHOWN);
    if (g_window == NULL) {
        fprintf(stderr, "Error: Could not create a window, %s\n",
                SDL_GetError());
        exit(-1);
    }
    g_win_surface = SDL_GetWindowSurface(g_window);
}

int window_get_event() {
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT:
            return -1;
        default:
            return 0;
        }
    }
    return 0;
}

void window_draw_rectangle() {
    SDL_FillRect(g_win_surface, NULL,
                 SDL_MapRGB(g_win_surface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(g_window);
}

void destroy_window() {
    SDL_DestroyWindow(g_window);
    SDL_Quit();
}
