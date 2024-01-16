#include "../content/terminalSize.h"
#include <ncurses.h>

terminalSize::terminalSize(int desiredRows, int desiredCols) : desiredRows(desiredRows), desiredCols(desiredCols) {
    initscr(); // Initialize ncurses
    timeout(0); // Non-blocking getch
}

terminalSize::~terminalSize() {
    endwin(); // Close ncurses
}

bool terminalSize::isTerminalSizeAchieved() {
    getmaxyx(stdscr, currentRows, currentCols); // Get current terminal size
    return (currentRows >= desiredRows && currentCols >= desiredCols);
}

void terminalSize::waitForTerminalSize() {
    while (!isTerminalSizeAchieved()) {
        clear();
        printw("Please resize your terminal to at least %dx%d.", desiredCols, desiredRows);
        refresh();
        getch(); // Non-blocking wait for a key press
    }
    clear();
}
