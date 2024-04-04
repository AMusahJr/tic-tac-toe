#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include "board.h"

#define WINDOW_TITLE "Tic Tac Toe"

extern SDL_Window *window;
extern SDL_Renderer *renderer;

int initializeGUI();
void closeGUI();

#endif // GUI_H

