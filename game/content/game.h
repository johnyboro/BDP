#ifndef BDP_GAME_H
#define BDP_GAME_H

#include "gameClock.h"

class game {
public:
    game(int tick, int port);
    ~game();

    void init();
    void mainMenu();
    void connect();
    void gameLoop();
    void quit();

private:
    int port;
    gameClock gameClock;
};

#endif //BDP_GAME_H
