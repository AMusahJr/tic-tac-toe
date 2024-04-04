// gui.c
#include "gui.h"
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 300
#define SCREEN_HEIGHT 300

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

void initializeGUI() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void closeGUI() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
