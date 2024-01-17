#include "../content/player.h"
#include <ncurses.h>

player::player(int x, int y, int initialVelocityX, int initialVelocityY)
        : x_(x), y_(y), velocityX_(initialVelocityX), velocityY_(initialVelocityY) {}

int player::getX() const { return x_; }

int player::getY() const { return y_; }

int player::getVelocityX() const { return velocityX_; }

int player::getVelocityY() const { return velocityY_; }

void player::setX(int x) { x_ = x; }

void player::setY(int y) { y_ = y; }

void player::setVelocityX(int velocityX) { velocityX_ = velocityX; }

void player::setVelocityY(int velocityY) { velocityY_ = velocityY; }

void player::update() {
    physics_.updatePosition(x_, y_, velocityX_, velocityX_);
}

void player::draw() const {
    mvprintw(y_, x_, "P"); // Assuming "P" represents the player on the screen
}