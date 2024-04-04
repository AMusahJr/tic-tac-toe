// player.h
#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char symbol;
    int row, col;
} Player;

void playerTurn(void* arg);

#endif
