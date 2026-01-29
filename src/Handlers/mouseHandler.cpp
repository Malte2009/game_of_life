#include <chrono>
#include <cmath>
#include <raylib.h>
#include <iostream>

#include "Game.h"

void handleMouse(Game* game) {

    if (IsMouseButtonDown(0)) {
        const int mouseX = GetMouseX();
        const int mouseY = GetMouseY();

        const int mouseXTile = std::ceil(mouseX / game->tileSize);
        const int mouseYTile = std::ceil(mouseY / game->tileSize);

        game->gameBoard[mouseXTile][mouseYTile] = 1;

        game->displayGameBoard();
    } else if (IsMouseButtonDown(1)) {
        const int mouseX = GetMouseX();
        const int mouseY = GetMouseY();

        const int mouseXTile = std::ceil(mouseX / game->tileSize);
        const int mouseYTile = std::ceil(mouseY / game->tileSize);

        game->gameBoard[mouseXTile][mouseYTile] = 0;

        game->displayGameBoard();
    }
}
