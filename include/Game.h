//
// Created by malte on 26.01.26.
//

#ifndef GAME_OF_LIFE_GAME_H
#define GAME_OF_LIFE_GAME_H
#include <vector>


class Game {
    public:
    std::vector<std::vector<int>> gameBoard;
    int windowSize;
    int gameBoardSize;
    int speed;
    bool isPaused;
    int lastPressedKey;

    Game(int newGameBoardSize);

    void startGame();

    private:
    void displayGameBoard();
    int getAmountOfSurroundingLivingCells(int x, int y) const;
    void spawnBlock(int x, int y);
    void spawnBeehive(int x, int y);
    void spawnBlinker(int x, int y);
    void spawnToad(int x, int y);
    void initializeRandom();

    void doGameLoop();

    void handleKeyboard();

    void openSpeedInput();
};


#endif //GAME_OF_LIFE_GAME_H