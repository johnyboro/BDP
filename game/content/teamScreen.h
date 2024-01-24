#ifndef BDP_TEAMSCREEN_H
#define BDP_TEAMSCREEN_H

#include "button.h"

class teamScreen {
public:
    teamScreen(int screenWidth, int screenHeight);

    void draw();
    void handleInput(int input);

    button teamAButton;
    button teamBButton;

private:
    int screenWidth, screenHeight;
    WINDOW* titleWindow;
};

#endif //BDP_TEAMSCREEN_H
