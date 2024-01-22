#include <ncurses.h>
#include <clocale>
#include "../content/game.h"
#include "../content/mainMenu.h"
#include "../content/terminalSize.h"
#include "../content/gameField.h"

game::game(int tick, int port, int terminalWidth, int terminalHeight) : gClock(tick), port(port), terminalWidth(terminalWidth), terminalHeight(terminalHeight) {}

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

    refresh(); // bo tak
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
        input = getch();
        mainMenu.handleInput(input);
    } while (input != 32);
    if(mainMenu.exitButton.isSelected){
        // nothing (you can't escape the matrix)
    }
    else if(mainMenu.startButton.isSelected) {
        clear();
    }
}

void game::connect() {
    // networking
    // blah blah blah
}

void game::startTeamScreen() {
    // team screen
    // bleh blah
}

void game::gameLoop() {
    gClock.startClock();
    oManager.addPlayer(35, 35);
    oManager.initPlayers();
    gameField gField(400, 80);
    nodelay(stdscr, TRUE);     // Enable non-blocking mode for getch
    int input;
    int i = 1;
    do {
        if(gClock.shouldUpdate()) {
            input = getch();
            flushinp(); // function to flush input buffer (very important)
            if (input != ERR) {
                oManager.inputPlayers(input);
            }
            oManager.updatePlayers();
            clear();
            oManager.drawPlayers();
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
