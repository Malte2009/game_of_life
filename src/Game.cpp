#include <vector>
#include <raylib.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

#include "../include/Game.h"
#include "../include/Handlers/keyboardHandler.h"
#include "../include/Handlers/mouseHandler.h"


Game::Game(const int newXSize, const int newYSize, int newTileSize) {

    if (newTileSize <= 1) exit(1);

    xSize = newXSize;
    ySize = newYSize;

    gameBoard = std::vector<std::vector<int>>(xSize, std::vector<int>(ySize, 0));

    tileSize = newTileSize;

    xTiles = std::floor(xSize / tileSize);
    yTiles = std::floor(ySize / tileSize);

    speed = 100;
    isPaused = false;
    lastPressedKey = 0;
    lastPainted = std::chrono::steady_clock::now();
}

void Game::startGame() {
    InitWindow(xSize, ySize, "Game of Life");
    SetTargetFPS(60);

    initializeRandom();

    BeginDrawing();
    ClearBackground(RAYWHITE);

    displayGameBoard();

    EndDrawing();

    int loopSpeed = 10;

    int counter = loopSpeed;

    int keyboardUpdateSpeed = 10;

    int mouseUpdateSpeed = 1;

    while (!WindowShouldClose()) {

        if (counter > speed && counter > keyboardUpdateSpeed) counter = loopSpeed;

        if (counter % keyboardUpdateSpeed == 0) handleKeyboard(this);

        if (counter % mouseUpdateSpeed == 0) handleMouse(this);

        std::this_thread::sleep_for(std::chrono::milliseconds(loopSpeed));

        if (counter % speed == 0) doGameLoop(); // Do game loop every speed ms

        counter += loopSpeed;
    }

    CloseWindow();
}

void Game::displayGameBoard() {
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
            if (i == 0 & j == 0) continue;

            if (x + i < 0 | y + j < 0) continue;

            if (x + i >= xTiles | y + j >= yTiles) continue;

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

    displayGameBoard();
}

void Game::resetBoard() {
    for (int x = 0; x < xTiles; x++) {
        for (int y = 0; y < yTiles; y++) {
            gameBoard[x][y] = 0;
        }
    }
}


void Game::spawnBlock(const int x, const int y) {
    if (x + 1 >= xTiles | y + 1 >= yTiles) return;

    gameBoard[x][y] = 1;
    gameBoard[x + 1][y] = 1;
    gameBoard[x][y + 1] = 1;
    gameBoard[x + 1][y + 1] = 1;
}

void Game::spawnBeehive(const int x, const int y) {
    if (x < 0 | y < 0) return;

    if (x + 2 >= xTiles | y + 3 >= yTiles) return;

    gameBoard[x + 1][y] = 1;
    gameBoard[x][y + 1] = 1;
    gameBoard[x][y + 2] = 1;
    gameBoard[x + 1][y + 3] = 1;
    gameBoard[x + 2][y + 1] = 1;
    gameBoard[x + 2][y + 2] = 1;
}

void Game::spawnBlinker(const int x, const int y) {
    if (x < 0 | y < 0) return;

    if (x + 3 >= xTiles | y + 3 >= yTiles) return;

    gameBoard[x + 1][y] = 1;
    gameBoard[x + 1][y + 1] = 1;
    gameBoard[x + 1][y + 2] = 1;
}

void Game::spawnToad(int x, int y) {
    if (x < 0 | y < 0) return;

    if (x + 3 >= xTiles | y + 3 >= yTiles) return;

    gameBoard[x][y + 1] = 1;
    gameBoard[x][y + 2] = 1;
    gameBoard[x + 1][y + 3] = 1;
    gameBoard[x + 2][y] = 1;
    gameBoard[x + 3][y + 1] = 1;
    gameBoard[x + 3][y + 2] = 1;
}
