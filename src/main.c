#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

#define WIDTH 640
#define HEIGHT 480

int main() {
    SDL_Window *window = NULL;
    SDL_Surface *winSurface;
    int quit = 0;
    SDL_Event event;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr, "Error: Could not initialize SDL, %s\n",
                SDL_GetError());
        return -1;
    }
    window = SDL_CreateWindow("2D Minecraft", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Error: Could not create a window %s\n",
                SDL_GetError());
        return -1;
    }
    winSurface = SDL_GetWindowSurface(window);
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        SDL_FillRect(winSurface, NULL,
                     SDL_MapRGB(winSurface->format, 0xFF, 0xFF, 0xFF));
        SDL_UpdateWindowSurface(window);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
