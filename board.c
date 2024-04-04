// board.c
#include "board.h"
#include "gui.h"
#include <stdio.h>
#include <SDL2/SDL.h>


char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    // Initialize the board with empty cells
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

int isGameOver() {
    // Check if the game is over (example logic)
    // You need to implement your own game over logic here
    // For example, you can check for a win condition or a tie
    return 0; // Placeholder return value
}

void renderBoard() {
    // Clear the renderer
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set color to white
    SDL_RenderClear(renderer);

    // Draw the grid lines
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set color to black
    for (int i = 1; i < BOARD_SIZE; i++) {
        // Vertical line
        SDL_RenderDrawLine(renderer, i * (SCREEN_WIDTH / BOARD_SIZE), 0, i * (SCREEN_WIDTH / BOARD_SIZE), SCREEN_HEIGHT);
        // Horizontal line
        SDL_RenderDrawLine(renderer, 0, i * (SCREEN_HEIGHT / BOARD_SIZE), SCREEN_WIDTH, i * (SCREEN_HEIGHT / BOARD_SIZE));
    }

    // Render the current state of the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            SDL_Rect cellRect = {j * (SCREEN_WIDTH / BOARD_SIZE), i * (SCREEN_HEIGHT / BOARD_SIZE),
                                 SCREEN_WIDTH / BOARD_SIZE, SCREEN_HEIGHT / BOARD_SIZE};
            if (board[i][j] == 'X') {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set color to red for X
                SDL_RenderFillRect(renderer, &cellRect);
            } else if (board[i][j] == 'O') {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Set color to blue for O
                SDL_RenderFillRect(renderer, &cellRect);
            } else {
                // Check for mouse click events
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (mouseX >= cellRect.x && mouseX < cellRect.x + cellRect.w &&
                    mouseY >= cellRect.y && mouseY < cellRect.y + cellRect.h &&
                    SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
                    // Left mouse button clicked in this cell
                    board[i][j] = 'X'; // Assuming player X makes the move
                }
            }
        }
    }

    // Present the renderer
    SDL_RenderPresent(renderer);
}


