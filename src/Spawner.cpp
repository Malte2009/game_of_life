#include "../include/Spawner.h"


void Spawner::spawnBlock(Game* game, const int x, const int y) {
    if (x < 0 || y < 0) return;

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

void Spawner::spawnBlinker(Game *game, const int x, const int y) {
    if (x < 0 || y < 0) return;

    if (x + 3 >= game->xTiles || y + 3 >= game->yTiles) return;

    game->gameBoard[x + 1][y] = 1;
    game->gameBoard[x + 1][y + 1] = 1;
    game->gameBoard[x + 1][y + 2] = 1;
}

void Spawner::spawnToad(Game *game, const int x, const int y) {
    if (x < 0 || y < 0) return;

    if (x + 3 >= game->xTiles || y + 3 >= game->yTiles) return;

    game->gameBoard[x][y + 1] = 1;
    game->gameBoard[x][y + 2] = 1;
    game->gameBoard[x + 1][y + 3] = 1;
    game->gameBoard[x + 2][y] = 1;
    game->gameBoard[x + 3][y + 1] = 1;
    game->gameBoard[x + 3][y + 2] = 1;
}

void Spawner::spawnClock(Game *game, const int x, const int y) {
    if (x < 0 || y < 0) return;

    if (x + 4 >= game->xTiles || y + 4 >= game->yTiles) return;

    game->gameBoard[x][y + 1] = 1;
    game->gameBoard[x + 1][y + 1] = 1;
    game->gameBoard[x + 1][y + 3] = 1;
    game->gameBoard[x + 2][y] = 1;
    game->gameBoard[x + 2][y + 2] = 1;
    game->gameBoard[x + 3][y + 2] = 1;
}

void Spawner::spawnBeacon(Game *game, const int x, const int y) {
    if (x < 0 || y < 0) return;

    if (x + 4 >= game->xTiles || y + 4 >= game->yTiles) return;

    game->gameBoard[x][y] = 1;
    game->gameBoard[x][y + 1] = 1;
    game->gameBoard[x + 1][y] = 1;
    game->gameBoard[x + 2][y + 3] = 1;
    game->gameBoard[x + 3][y + 2] = 1;
    game->gameBoard[x + 3][y + 3] = 1;
}

void Spawner::spawnPulsar(Game *game, int x, int y) {
    if (x < 0 || y < 0) return;

    if (x + 15 >= game->xTiles || y + 15 >= game->yTiles) return;

    game->gameBoard[x + 1][y + 5] = 1;
    game->gameBoard[x + 1][y + 11] = 1;
    game->gameBoard[x + 2][y + 5] = 1;
    game->gameBoard[x + 2][y + 11] = 1;
    game->gameBoard[x + 3][y + 5] = 1;
    game->gameBoard[x + 3][y + 11] = 1;
    game->gameBoard[x + 3][y + 6] = 1;
    game->gameBoard[x + 3][y + 10] = 1;

    game->gameBoard[x + 5][y + 1] = 1;
    game->gameBoard[x + 5][y + 2] = 1;
    game->gameBoard[x + 5][y + 3] = 1;
    game->gameBoard[x + 5][y + 6] = 1;
    game->gameBoard[x + 5][y + 7] = 1;
    game->gameBoard[x + 5][y + 9] = 1;
    game->gameBoard[x + 5][y + 10] = 1;
    game->gameBoard[x + 5][y + 13] = 1;
    game->gameBoard[x + 5][y + 14] = 1;
    game->gameBoard[x + 5][y + 15] = 1;

    game->gameBoard[x + 6][y + 3] = 1;
    game->gameBoard[x + 6][y + 5] = 1;
    game->gameBoard[x + 6][y + 7] = 1;
    game->gameBoard[x + 6][y + 9] = 1;
    game->gameBoard[x + 6][y + 11] = 1;
    game->gameBoard[x + 6][y + 13] = 1;

    game->gameBoard[x + 7][y + 5] = 1;
    game->gameBoard[x + 7][y + 6] = 1;
    game->gameBoard[x + 7][y + 10] = 1;
    game->gameBoard[x + 7][y + 11] = 1;

    game->gameBoard[x + 9][y + 5] = 1;
    game->gameBoard[x + 9][y + 6] = 1;
    game->gameBoard[x + 9][y + 10] = 1;
    game->gameBoard[x + 9][y + 11] = 1;

    game->gameBoard[x + 10][y + 3] = 1;
    game->gameBoard[x + 10][y + 5] = 1;
    game->gameBoard[x + 10][y + 7] = 1;
    game->gameBoard[x + 10][y + 9] = 1;
    game->gameBoard[x + 10][y + 11] = 1;
    game->gameBoard[x + 10][y + 13] = 1;

    game->gameBoard[x + 11][y + 1] = 1;
    game->gameBoard[x + 11][y + 2] = 1;
    game->gameBoard[x + 11][y + 3] = 1;
    game->gameBoard[x + 11][y + 6] = 1;
    game->gameBoard[x + 11][y + 7] = 1;
    game->gameBoard[x + 11][y + 9] = 1;
    game->gameBoard[x + 11][y + 10] = 1;
    game->gameBoard[x + 11][y + 13] = 1;
    game->gameBoard[x + 11][y + 14] = 1;
    game->gameBoard[x + 11][y + 15] = 1;

    game->gameBoard[x + 13][y + 5] = 1;
    game->gameBoard[x + 13][y + 11] = 1;
    game->gameBoard[x + 13][y + 6] = 1;
    game->gameBoard[x + 13][y + 10] = 1;
    game->gameBoard[x + 14][y + 5] = 1;
    game->gameBoard[x + 14][y + 11] = 1;

    game->gameBoard[x + 15][y + 5] = 1;
    game->gameBoard[x + 15][y + 11] = 1;
}
