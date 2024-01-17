#include <ncurses.h>
#include <clocale>
#include "../content/game.h"
#include "../content/mainMenu.h"
#include "../content/terminalSize.h"

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

    refresh(); // TO MUSI TU BYĆ BO NCURSES JEST BROKEN I TYLKO BÓG WIE CZEMU :(
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
    } while (input != 27);
}

void game::connect() {
    // networking
}

void game::startTeamScreen() {
    // team screen
}

void game::gameLoop() {
    gClock.startClock();
    // game
}

void game::quit() {
    // cleanup and quit;
    endwin();
}
