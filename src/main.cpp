#include <iostream>

#include "../include/Game.h"
#include "raylib.h"

int main() {
    const int gameBoardSize = 50;

    Game testGame(gameBoardSize);

    testGame.startGame();
}
