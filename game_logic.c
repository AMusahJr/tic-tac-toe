#include "board.h"
#include "gui.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include "game_logic.h"

char board[BOARD_SIZE][BOARD_SIZE];

// Function to check if there is a winner
char checkWinner() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    // No winner found
    return ' ';
}

// Function to check if the board is full (indicating a tie)
int isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

// Function to check if the game is over
int isGameOver() {
    char winner = checkWinner();
    if (winner != ' ') {
        return 1; // Game over: there is a winner
    }
    if (isBoardFull()) {
        return 1; // Game over: board is full (tie)
    }
    return 0; // Game is still ongoing
}

