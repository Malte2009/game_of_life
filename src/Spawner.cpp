#include "../include/Spawner.h"


void Spawner::spawnBlock(Game* game, const int x, const int y) {

    if (x + 1 >= game->xTiles || y + 1 >= game->yTiles) return;

    game->gameBoard[x][y] = 1;
    game->gameBoard[x + 1][y] = 1;
    game->gameBoard[x][y + 1] = 1;
    game->gameBoard[x + 1][y + 1] = 1;
}

void Spawner::spawnBeehive(Game* game, const int x, const int y) {
    if (x < 0 || y < 0) return;

    if (x + 2 >= game->xTiles || y + 3 >= game->yTiles) return;

    game->gameBoard[x + 1][y] = 1;
    game->gameBoard[x][y + 1] = 1;
    game->gameBoard[x][y + 2] = 1;
    game->gameBoard[x + 1][y + 3] = 1;
    game->gameBoard[x + 2][y + 1] = 1;
    game->gameBoard[x + 2][y + 2] = 1;
}

void Spawner::spawnBlinker(Game *game, int x, int y) {
    if (x < 0 || y < 0) return;

    if (x + 3 >= game->xTiles || y + 3 >= game->yTiles) return;

    game->gameBoard[x + 1][y] = 1;
    game->gameBoard[x + 1][y + 1] = 1;
    game->gameBoard[x + 1][y + 2] = 1;
}

void Spawner::spawnToad(Game *game, int x, int y) {
    if (x < 0 || y < 0) return;

    if (x + 3 >= game->xTiles || y + 3 >= game->yTiles) return;

    game->gameBoard[x][y + 1] = 1;
    game->gameBoard[x][y + 2] = 1;
    game->gameBoard[x + 1][y + 3] = 1;
    game->gameBoard[x + 2][y] = 1;
    game->gameBoard[x + 3][y + 1] = 1;
    game->gameBoard[x + 3][y + 2] = 1;
}
