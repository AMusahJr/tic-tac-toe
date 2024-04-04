// board.h
#ifndef BOARD_H
#define BOARD_H

void initializeBoard();
void renderBoard();
int isValidMove(int row, int col);
int isGameOver();
void makeMove(int row, int col, char symbol);

#endif
