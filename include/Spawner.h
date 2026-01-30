#ifndef GAME_OF_LIFE_SPAWNER_H
#define GAME_OF_LIFE_SPAWNER_H

#include "Game.h"

class Spawner {
    public:
    static void spawnBlock(Game* game, int x, int y);
    static void spawnBeehive(Game* game, int x, int y);
    static void spawnBlinker(Game* game, int x, int y);
    static void spawnToad(Game* game, int x, int y);
    static void spawnClock(Game* game, int x, int y);
    static void spawnBeacon(Game* game, int x, int y);
    static void spawnPulsar(Game* game, int x, int y);
};


#endif //GAME_OF_LIFE_SPAWNER_H