#include <chrono>
#include <cmath>
#include <raylib.h>
#include <iostream>

#include "Game.h"

void handleMouse(Game* game) {

    const double msSinceLastClick = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - game->lastPainted).count();

    if (IsMouseButtonDown(0) && msSinceLastClick > 100) {
        const int mouseX = GetMouseX();
        const int mouseY = GetMouseY();

        const int mouseXTile = std::ceil(mouseX / game->tileSize);
        const int mouseYTile = std::ceil(mouseY / game->tileSize);

        std::cout << mouseXTile << std::endl;

        std::cout << mouseYTile << std::endl;

        game->gameBoard[mouseXTile][mouseYTile] = !game->gameBoard[mouseXTile][mouseYTile];

        game->displayGameBoard();

        game->lastPainted = std::chrono::steady_clock::now();
    }
}
