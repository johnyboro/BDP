#include "../content/gameField.h"
#include <algorithm>

gameField::gameField(int width, int height) : width(width), height(height) {
    pad = newpad(height, width);
}

gameField::~gameField() {
    delwin(pad);
}

void gameField::draw() {
    refresh();
    prefresh(pad, 0, 0, 0, 0, LINES - 1, COLS - 1);
}

void gameField::follow(int playerX, int playerY) {
    // Calculate the top-left corner coordinates for the player-centered view
    int viewX = std::max(0, playerX - COLS / 2);
    int viewY = std::max(0, playerY - LINES / 2);

    // Move the pad's viewport to the calculated position
    prefresh(pad, viewY, viewX, 0, 0, LINES - 1, COLS - 1);
}

void gameField::updateContent(const char* content) {
    // Update the content of the pad
    mvwprintw(pad, 0, 0, content);
}