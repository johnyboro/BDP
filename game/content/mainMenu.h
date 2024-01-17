#ifndef MAINMENU_H
#define MAINMENU_H

#include "button.h"

class mainMenu {
public:
    mainMenu(int screenWidth, int screenHeight);

    void draw();
    void handleInput(int input);

    button startButton;
    button exitButton;

private:
    int screenWidth, screenHeight;
    WINDOW* titleWindow;
};

#endif // MAINMENU_H
