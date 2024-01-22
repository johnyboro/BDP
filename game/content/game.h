#ifndef BDP_GAME_H
#define BDP_GAME_H

#include "gameClock.h"
#include "objectManager.h"

class game {
public:
    game(int tick, int port, int terminalWidth, int terminalHeight);
    ~game();

    void init();
    void waitForTerminal();
    void startMainMenu();
    void connect();
    void startTeamScreen();
    void gameLoop();
    void quit();

private:
    int port;
    gameClock gClock;
    objectManager oManager;

    int terminalWidth;
    int terminalHeight;
};

#endif //BDP_GAME_H
