#include <iostream>

#include "../include/Game.h"

int main(int argc, char *argv[]) {

    try {
        const int xSize = std::stoll(argv[1]);
        const int ySize = std::stoll(argv[2]);
        const int tileSize = std::stoll(argv[3]);

        const bool showWindow = argv[4];

        Game game(xSize, ySize, tileSize, showWindow);

        game.startGame();
    } catch (...) {
        std::cerr << "Invalid cmd arguments";
    }
}
