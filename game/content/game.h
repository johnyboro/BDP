#ifndef BDP_GAME_H
#define BDP_GAME_H

#include "gameClock.h"
#include "objectManager.h"
#include "../../networking/content/client.h"

class game {
public:
    game(int tick, const char* port, int terminalWidth, int terminalHeight);
    ~game();

    void init();
    void waitForTerminal();
    void startMainMenu();
    void startTeamScreen();
    void connect();
    void gameLoop();
    void quit();

    bool doQuit;

private:
    const char* port;
    gameClock gClock;
    objectManager oManager;
    client gClient;

    int terminalWidth;
    int terminalHeight;
};

#endif //BDP_GAME_H
