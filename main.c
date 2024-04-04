// main.c
#include <stdio.h>
#include "board.h"
#include "player.h"
#include "gui.h"

int main() {
    Player players[2]; // Define players array
    initializeBoard();
    initializeGUI();
    players[0].symbol = 'X';
    players[1].symbol = 'O';
    playerTurn(&players[0]);
    closeGUI();
    return 0;
}
