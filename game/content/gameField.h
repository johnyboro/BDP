#ifndef BDP_GAMEFIELD_H
#define BDP_GAMEFIELD_H

#include <ncurses.h>

class gameField {
private:
    WINDOW* pad;
    int width, height;

public:
    gameField(int width, int height);
    ~gameField();

    void draw();
    void follow(int playerX, int playerY);
    void updateContent(const char* content);
};

#endif //BDP_GAMEFIELD_H
