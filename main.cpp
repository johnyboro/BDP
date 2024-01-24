#include "game/content/game.h"

int main() {
    game game(15, "localhost", 200, 50);
    game.init();
    game.waitForTerminal();
    game.startMainMenu();
    if(game.doQuit)
        return 0;
    game.startTeamScreen();
    game.connect();
    game.gameLoop();

    return 0;
}