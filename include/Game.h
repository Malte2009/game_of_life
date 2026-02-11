#ifndef GAME_OF_LIFE_GAME_H
#define GAME_OF_LIFE_GAME_H

#include <vector>
#include <chrono>


class Game {
    public:
    std::vector<std::vector<int>> gameBoard;
    int xSize;
    int ySize;
    int speed;
    bool isPaused;
    int lastPressedKey;
    int tileSize;
    int xTiles;
    int yTiles;
    bool showWindow;

    explicit Game(int xSize, int ySize, int tileSize, bool showWindow);

    void startGame();
    void initializeRandom();
    void displayGameBoard() const;
    void resetBoard();

    private:
    int getAmountOfSurroundingLivingCells(int x, int y) const;

    void doGameLoop();
};


#endif //GAME_OF_LIFE_GAME_H