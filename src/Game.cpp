#include <vector>
#include <raylib.h>
#include <iostream>

#include "../include/Game.h"

#include <chrono>
#include <thread>

Game::Game(const int newGameBoardSize) {
    gameBoard = std::vector<std::vector<int>>(newGameBoardSize, std::vector<int>(newGameBoardSize, 0));

    windowSize = newGameBoardSize * 20;
    gameBoardSize = newGameBoardSize;
    speed = 100;
    isPaused = false;
    lastPressedKey = 0;

}

void Game::startGame() {
    InitWindow(windowSize, windowSize, "Game of Life");
    SetTargetFPS(60);

    initializeRandom();

    BeginDrawing();
    ClearBackground(RAYWHITE);

    displayGameBoard();

    EndDrawing();

    int loopSpeed = 10;

    int counter = loopSpeed;

    int keyboardUpdateSpeed = 10;

    while (!WindowShouldClose()) {

        if (counter > speed && counter > keyboardUpdateSpeed) counter = loopSpeed;

        if (counter % speed == 0) doGameLoop(); // Do game loop every speed ms

        if (counter % keyboardUpdateSpeed == 0) handleKeyboard(); // Check every 40ms for input and handle it

        counter += loopSpeed;

        std::this_thread::sleep_for(std::chrono::milliseconds(loopSpeed));
    }

    CloseWindow();
}

void Game::displayGameBoard() {
    const int cellSize = windowSize / gameBoard.size();
    for (int i = 0; i < gameBoard.size(); i++) {
        for (int j = 0; j < gameBoard[i].size(); j++) {
            DrawRectangle(i * cellSize, j * cellSize, cellSize - cellSize * 0.1, cellSize - cellSize * 0.1, gameBoard[i][j] == 1 ? BLACK : LIGHTGRAY);
        }
    }
}

int Game::getAmountOfSurroundingLivingCells(const int x, const int y) const {
    int surroundingLivingCells = 0;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 & j == 0) continue;

            if (x + i < 0 | y + j < 0) continue;

            if (x + i >= gameBoardSize | y + j >= gameBoardSize) continue;

            surroundingLivingCells += gameBoard[x + i][y + j];
        }
    }

    return surroundingLivingCells;
}

void Game::initializeRandom() {
    srand(time(0));
    for (int i = 0; i < gameBoardSize; i++) {
        for (int j = 0; j < gameBoardSize; j++) {
            gameBoard[i][j] = rand() % 2;
        }
    }
}

void Game::doGameLoop() {
    BeginDrawing();

    auto newGameBoard = gameBoard;

    for (int x = 0; x < gameBoardSize; x++) {
        for (int y = 0; y < gameBoard[x].size(); y++) {
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

    ClearBackground(RAYWHITE);

    EndDrawing();
}

void Game::handleKeyboard() {

    int pressedKey = GetKeyPressed();
    std::cout << pressedKey << std::endl;
    switch (pressedKey) {
        case 32:
            // space
            isPaused = !isPaused;
            break;
        case 333:
        case 47:
            speed += 10;
            break;
        case 334:
        case 93:
            if (speed == 10) break;
            speed -= 10;
            break;
        case 82:
            initializeRandom();
            break;
        default:
            break;
    }
}

void Game::spawnBlock(const int x, const int y) {
    if (x + 1 >= gameBoardSize | y + 1 >= gameBoardSize) return;

    gameBoard[x][y] = 1;
    gameBoard[x + 1][y] = 1;
    gameBoard[x][y + 1] = 1;
    gameBoard[x + 1][y + 1] = 1;
}

void Game::spawnBeehive(const int x, const int y) {
    if (x < 0 | y < 0) return;

    if (x + 2 >= gameBoardSize | y + 3 >= gameBoardSize) return;

    gameBoard[x + 1][y] = 1;
    gameBoard[x][y + 1] = 1;
    gameBoard[x][y + 2] = 1;
    gameBoard[x + 1][y + 3] = 1;
    gameBoard[x + 2][y + 1] = 1;
    gameBoard[x + 2][y + 2] = 1;
}

void Game::spawnBlinker(const int x, const int y) {
    if (x < 0 | y < 0) return;

    if (x + 3 >= gameBoardSize | y + 3 >= gameBoardSize) return;

    gameBoard[x + 1][y] = 1;
    gameBoard[x + 1][y + 1] = 1;
    gameBoard[x + 1][y + 2] = 1;
}

void Game::spawnToad(int x, int y) {
    if (x < 0 | y < 0) return;

    if (x + 3 >= gameBoardSize | y + 3 >= gameBoardSize) return;

    gameBoard[x][y + 1] = 1;
    gameBoard[x][y + 2] = 1;
    gameBoard[x + 1][y + 3] = 1;
    gameBoard[x + 2][y] = 1;
    gameBoard[x + 3][y + 1] = 1;
    gameBoard[x + 3][y + 2] = 1;
}
