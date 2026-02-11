#include <vector>
#include <raylib.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

#include "../include/Game.h"

#include "Spawner.h"
#include "../include/Handlers/keyboardHandler.h"
#include "../include/Handlers/mouseHandler.h"


Game::Game(const int xSize, const int ySize, const int tileSize, const bool showWindow) {

    if (tileSize <= 1) exit(1);

    this->xSize = xSize;
    this->ySize = ySize;
    this->tileSize = tileSize;
    this->showWindow = showWindow;

    gameBoard = std::vector<std::vector<int>>(xSize, std::vector<int>(ySize, 0));

    xTiles = std::floor(xSize / tileSize);
    yTiles = std::floor(ySize / tileSize);

    speed = 10;
    isPaused = false;
    lastPressedKey = 0;
}

void Game::startGame() {

    if (showWindow) {
        InitWindow(xSize, ySize, "Game of Life");
        SetTargetFPS(60);
    }

    initializeRandom();

    if (showWindow) displayGameBoard();


    constexpr int loopSpeed = 10;

    int counter = loopSpeed;

    while (!WindowShouldClose() || !showWindow) {
        const auto startTime = std::chrono::high_resolution_clock::now();

        if (counter > speed) counter = loopSpeed;

        handleKeyboard(this);

        handleMouse(this);

        std::this_thread::sleep_for(std::chrono::milliseconds(loopSpeed));

        if (counter % speed == 0) doGameLoop();

        if (counter % 10 == 0) std::cout << std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - startTime).count() << std::endl;

        counter += loopSpeed;
    }

    CloseWindow();
}

void Game::displayGameBoard() const {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (int x = 0; x < xTiles; x++) {
        for (int y = 0; y < yTiles; y++) {
            //if (y % 2 == 0) continue;
            DrawRectangle(x * tileSize, y * tileSize, tileSize - tileSize * 0.1, tileSize - tileSize * 0.1, gameBoard[x][y] ? BLACK : LIGHTGRAY);
        }
    }

    EndDrawing();
}

int Game::getAmountOfSurroundingLivingCells(const int x, const int y) const {
    int surroundingLivingCells = 0;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) continue;

            if (x + i < 0 || y + j < 0) continue;

            if (x + i >= xTiles || y + j >= yTiles) continue;

            surroundingLivingCells += gameBoard[x + i][y + j];
        }
    }

    return surroundingLivingCells;
}

void Game::initializeRandom() {
    srand(time(0));
    for (int x = 0; x < xTiles; x++) {
        for (int y = 0; y < yTiles; y++) {
            gameBoard[x][y] = rand() % 2;
        }
    }
}

void Game::doGameLoop() {
    auto newGameBoard = gameBoard;

    for (int x = 0; x < xTiles; x++) {
        for (int y = 0; y < yTiles; y++) {
            const int surroundingCells = getAmountOfSurroundingLivingCells(x,y);

            if (isPaused) continue;

            if (surroundingCells == 2) {
                continue;
            }

            if (surroundingCells == 3) {
                newGameBoard[x][y] = 1;
                continue;
            }

            newGameBoard[x][y] = 0;
        }
    }

    gameBoard = newGameBoard;

    if (showWindow) displayGameBoard();
}

void Game::resetBoard() {
    for (int x = 0; x < xTiles; x++) {
        for (int y = 0; y < yTiles; y++) {
            gameBoard[x][y] = 0;
        }
    }
}