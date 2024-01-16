#include <ncurses.h>
#include <clocale>
#include "../content/game.h"
#include "../content/mainMenu.h"

game::game(int tick, int port) : gClock(tick), port(port) {}

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
}

void game::mainMenu() {
//    mainMenu mainMenu;
}

void game::connect() {
    // networking
}

void game::teamScreen() {
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
