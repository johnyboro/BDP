#include "../content/mainMenu.h"

mainMenu::mainMenu(int screenWidth, int screenHeight)
        : screenWidth(screenWidth),
          screenHeight(screenHeight),
          startButton(screenWidth / 2 - 10, screenHeight / 2 - 2, 20, 5, "Start"),
          exitButton(screenWidth / 2 - 10, screenHeight / 2 + 3, 20, 5, "Exit") {
    // Initialize colors for the title
    init_pair(3, COLOR_CYAN, COLOR_BLACK);

    // Create a window for the title
    titleWindow = newwin(3, screenWidth, 0, 0);
}

void mainMenu::draw() {
    // Draw the title
    wattron(titleWindow, COLOR_PAIR(3));
    mvwprintw(titleWindow, 1, screenWidth / 2 - 5, "Main Menu");
    wattroff(titleWindow, COLOR_PAIR(3));
    wrefresh(titleWindow);

    startButton.draw();
    exitButton.draw();
}

void mainMenu::handleInput(int input) {
    switch (input) {
        case KEY_UP:
            exitButton.isSelected = false;
            startButton.isSelected = true;
            break;
        case KEY_DOWN:
            exitButton.isSelected = true;
            startButton.isSelected = false;
            break;
    }
}