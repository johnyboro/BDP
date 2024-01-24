#include "../content/teamScreen.h"

teamScreen::teamScreen(int screenWidth, int screenHeight)
        : screenWidth(screenWidth),
          screenHeight(screenHeight),
          teamAButton(screenWidth / 2 + 20, screenHeight / 2 - 2, 20, 5, "TEAM GREEN"),
          teamBButton(screenWidth / 2 - 30, screenHeight / 2 - 2, 20, 5, "TEAM RED") {
    // Initialize colors for the title
    init_pair(3, COLOR_RED, COLOR_BLACK);

    // Create a window for the title
    titleWindow = newwin(3, screenWidth, 0, 0);
}

void teamScreen::draw() {
    // Draw the title
    wattron(titleWindow, COLOR_PAIR(3));
    mvwprintw(titleWindow, 1, screenWidth / 2 - 5, "Choose team: ");
    wattroff(titleWindow, COLOR_PAIR(3));
    wrefresh(titleWindow);

    teamAButton.draw();
    teamBButton.draw();
}

void teamScreen::handleInput(int input) {
    switch (input) {
        case 'a':
            teamAButton.isSelected = false;
            teamBButton.isSelected = true;
            break;
        case 'd':
            teamAButton.isSelected = true;
            teamBButton.isSelected = false;
            break;
    }
}