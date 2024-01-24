#include "../content/mainMenu.h"

mainMenu::mainMenu(int screenWidth, int screenHeight)
        : screenWidth(screenWidth),
          screenHeight(screenHeight),
          startButton(screenWidth / 2 - 10, screenHeight / 2 - 2, 20, 5, "Start"),
          exitButton(screenWidth / 2 - 10, screenHeight / 2 + 3, 20, 5, "Exit") {
    // Initialize colors for the title
    init_pair(3, COLOR_RED, COLOR_BLACK);

    // Create a window for the title
    titleWindow = newwin(screenHeight/2 -5, screenWidth, 0, screenWidth / 2 - 38);
}

void mainMenu::draw() {
    // Draw the title
    wattron(titleWindow, COLOR_PAIR(3));
    mvwprintw(titleWindow, 1, screenWidth / 2 - 5, R"(

 _____ _   _ _____   ____    _    _     _        ____    _    __  __ _____
|_   _| | | | ____| | __ )  / \  | |   | |      / ___|  / \  |  \/  | ____|
  | | | |_| |  _|   |  _ \ / _ \ | |   | |     | |  _  / _ \ | |\/| |  _|
  | | |  _  | |___  | |_) / ___ \| |___| |___  | |_| |/ ___ \| |  | | |___
  |_| |_| |_|_____| |____/_/   \_\_____|_____|  \____/_/   \_\_|  |_|_____|

)");
    wattroff(titleWindow, COLOR_PAIR(3));
    wrefresh(titleWindow);

    startButton.draw();
    exitButton.draw();
}

void mainMenu::handleInput(int input) {
    switch (input) {
        case 'w':
            exitButton.isSelected = false;
            startButton.isSelected = true;
            break;
        case 's':
            exitButton.isSelected = true;
            startButton.isSelected = false;
            break;
    }
}