#include <ncurses.h>
#include <clocale>
#include <chrono> // for tests
#include <iostream> // for tests
#include "../content/game.h"
#include "../content/gameClock.h"
#include "../content/mainMenu.h"

game::game(int tick, int port) : gameClock(tick), port(port) {}

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
    //networking
}

void game::gameLoop() {
    gameClock.startClock();
    while (true) {
        if (gameClock.shouldUpdate()) {
            std::cout << "Update at: " << std::chrono::steady_clock::now().time_since_epoch().count() << std::endl;

            // Simulate other work in your game loop
            // You can replace this with your actual game logic
            // For simplicity, we'll just print "Working..."
            std::cout << "Working..." << std::endl;
        }
    }
    //game
}
