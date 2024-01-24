#include <ncurses.h>
#include <clocale>
#include "../content/game.h"
#include "../content/mainMenu.h"
#include "../content/terminalSize.h"
#include "../content/teamScreen.h"

game::game(int tick, const char* port, int terminalWidth, int terminalHeight)
            : gClock(tick), port(port), terminalWidth(terminalWidth), terminalHeight(terminalHeight), doQuit(false) {}

game::~game() {
    quit();
}

void game::init() {
    setlocale(LC_ALL, "en_US.UTF-8"); // set for unicode
    initscr();            // Initialize ncurses
    raw();                // Disable line buffering
    keypad(stdscr, TRUE); // Enable special keys
    noecho();             // Do not display input characters
    curs_set(0);          // Hide the cursor
    start_color();        // Enable color

    refresh(); // yes
}

void game::waitForTerminal() {
    terminalSize screen(terminalHeight, terminalWidth);
    screen.waitForTerminalSize(); // Wait for user to resize the terminal
}

void game::startMainMenu() {
    mainMenu mainMenu(terminalWidth, terminalHeight);
    int input;
    do {
        mainMenu.draw();
        refresh();
        input = getch();
        mainMenu.handleInput(input);
    } while(input != 32);
    if(mainMenu.exitButton.isSelected) {
        clear();
        doQuit = true;
    }
    else if(mainMenu.startButton.isSelected) {
        clear();
    }
}

void game::startTeamScreen() {
    teamScreen teamScreen(terminalWidth, terminalHeight);
    int input;
    do {
        teamScreen.draw();
        refresh();
        input = getch();
        teamScreen.handleInput(input);
    } while(input != 32);
    if(teamScreen.teamAButton.isSelected) {
        clear();
        oManager.addLocalPlayer(1);
    }
    else if(teamScreen.teamBButton.isSelected) {
        clear();
        oManager.addLocalPlayer(2);
    }
}

void game::connect() {
    // networking
    // blah blah blah
    gClient.connect(port);
}

void game::gameLoop() {
    gClock.startClock();
    nodelay(stdscr, TRUE);     // Enable non-blocking mode for getch
    int input;
    int i = 1;
    do {
        if(gClock.shouldUpdate()) {
            input = getch();
            flushinp(); // function to flush input buffer (very important)
            gClient.update(oManager);
            if (input != ERR) {
                oManager.inputLocalPlayers(input);
            }
            oManager.updatePlayers();
            gClient.sendPlayerUpdate(oManager.packLocalUpdate());
            clear();
            oManager.drawPlayers();
            // debug
            mvprintw(1, 1, "tick count: %d", i);
            mvprintw(3, 1, "input: %d", input);
            refresh();
            i++;
        }
    } while (input != 'q');

}

void game::quit() {
    // cleanup and quit;
    endwin();
}
