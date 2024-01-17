#include "../content/terminalSize.h"
#include "../content/button.h"
#include <ncurses.h>

terminalSize::terminalSize(int desiredRows, int desiredCols) : desiredRows(desiredRows), desiredCols(desiredCols) {
    initscr(); // Initialize ncurses
//    timeout(0); // Non-blocking getch
}

terminalSize::~terminalSize() = default;

bool terminalSize::isTerminalSizeAchieved() {
    getmaxyx(stdscr, currentRows, currentCols); // Get current terminal size
    return (currentRows >= desiredRows && currentCols >= desiredCols);
}

void terminalSize::waitForTerminalSize() {
    getmaxyx(stdscr, currentRows, currentCols);
    button sign(currentCols/2 - 25, currentRows/2 - 1, 50, 3, "Please make your little terminal bigger <3");
    while (!isTerminalSizeAchieved()) {
        sign.draw();
        refresh();
//        getch(); // Non-blocking wait for a key press
    }
    clear();
}
