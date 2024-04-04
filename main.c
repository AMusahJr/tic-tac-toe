#include "player.h"
#include "board.h"
#include "gui.h"
#include "game_logic.h" // Include game_logic.h to access playerTurn function
#include <stdio.h>
#include <SDL2/SDL.h>

int main() {
    Player players[2]; // Define players array
    initializeBoard();
    if (!initializeGUI()) {
        fprintf(stderr, "Failed to initialize GUI\n");
        return 1;
    }
    players[0].symbol = 'X';
    players[1].symbol = 'O';
    playerTurn(&players[0]);
    // Keep the program running until the GUI window is closed
    while (!isGameOver()) {
        SDL_PumpEvents(); // Update event queue
        renderBoard(); // Update the board on the GUI window
        SDL_Delay(100); // Add a small delay to reduce CPU usage
    }
    closeGUI();
    return 0;
}

