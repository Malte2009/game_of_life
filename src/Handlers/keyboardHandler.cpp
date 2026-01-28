#include <raylib.h>
#include <iostream>

#include "../../include/Handlers/keyboardHandler.h"

#include "../../include/Game.h"

void handleKeyboard(Game* game) {

    int pressedKey = GetKeyPressed();
    switch (pressedKey) {
        case 32:
            // space
            game->isPaused = !game->isPaused;
            break;
        case 333:
        case 47:
            game->speed += 10;
            break;
        case 334:
        case 93:
            if (game->speed == 10) break;
            game->speed -= 10;
            break;
        case 82:
            game->initializeRandom();
            break;
        case 67:
            game->resetBoard();
        default:
            break;
    }
}