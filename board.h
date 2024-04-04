

#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 3
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

extern char board[BOARD_SIZE][BOARD_SIZE];

void renderBoard();
void initializeBoard();
int isGameOver();

#endif // BOARD_H

