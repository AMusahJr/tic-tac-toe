// board.c
#include <stdio.h>
#include "board.h"

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void renderBoard() {
    printf("-------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("|");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

int isValidMove(int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ');
}

int isGameOver() {
    // Implement game-over logic here
    return 0; // Placeholder return value
}

void makeMove(int row, int col, char symbol) {
    board[row][col] = symbol;
}
