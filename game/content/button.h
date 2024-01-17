#ifndef BUTTON_H
#define BUTTON_H

#include <ncurses.h>
#include <string>

class button {
public:
    button(int x, int y, int width, int height, const char* label);

    void draw();
//    void onSelect(); deprecated

    bool isSelected;

private:
    int x, y, width, height;
    std::string label;
    WINDOW* window;
};

#endif // BUTTON_H
