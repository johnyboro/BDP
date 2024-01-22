#include "game/content/game.h"
#include "game/content/button.h"
#include <ncurses.h>

int main() {
    game game(30, 1234, 200, 50);
    game.init();
    game.waitForTerminal();
//    game.startMainMenu();
    game.gameLoop();

    game.quit();
    return 0;
}