#include "../content/player.h"
#include <ncurses.h>
#include <cmath>

player::player(int id, int x, int y, int team, int initialVelocityX, int initialVelocityY, int speed, int gravity, int drag, int bounciness, int r, const char* ch)
        : id_(id), x_(x), y_(y), team_(team), velocityX_(initialVelocityX), velocityY_(initialVelocityY), speed_(speed), gravity_(gravity), drag_(drag), bounciness_(bounciness), r_(r), ch_(ch),
          physics_(gravity, drag, bounciness) {}

int player::getX() const { return x_; }
int player::getY() const { return y_; }
int player::getVelocityX() const { return velocityX_; }
int player::getVelocityY() const { return velocityY_; }
int player::getTeam() const { return team_; }
int player::getId() const { return id_; }

void player::setX(int x) { x_ = x; }
void player::setY(int y) { y_ = y; }
void player::setVelocityX(int velocityX) { velocityX_ = velocityX; }
void player::setVelocityY(int velocityY) { velocityY_ = velocityY; }

void player::initCircle() {
    init_pair(1, COLOR_GREEN, COLOR_BLACK);  // Team 1
    init_pair(2, COLOR_RED, COLOR_BLACK); // Team 2
    // precompute circle
    for (int i = -r_; i <= r_; ++i) {
        for (int j = -r_; j <= r_; ++j) {
            if (std::sqrt(i * i + j * j) <= r_) {
                circlePositions_.emplace_back(j, i);
            }
        }
    }
}

void player::handleInput(int input) {
    switch (input) {
        case 'w':
            setY(getY() - 5);
            break;
        case 'a':
            setVelocityX(getVelocityX() - speed_);
            break;
        case 'd':
            setVelocityX(getVelocityX() + speed_);
            break;
        default:
            break;
    }
}

void player::update() {
//    physics_.applyGravity(velocityY_);
    physics_.applyDrag(velocityX_);
    physics_.applyDrag(velocityY_);
    physics_.applyVelocity(x_, velocityX_);
    physics_.applyVelocity(y_, velocityY_);
}

void player::draw() const {
    int color_selection;
    if(getTeam() == 1)
        color_selection = 1;
    else
        color_selection = 2;
    wattron(stdscr, COLOR_PAIR(color_selection));
    // Draw precomputed circle
    for (const auto& pos : circlePositions_) {
        mvprintw(y_ + pos.second, x_ + 2 * pos.first, ch_);
    }
    wattroff(stdscr, COLOR_PAIR(color_selection));
}

bCircle player::getBoundingCircle() const {
    // Circular hitbox around the player's position
    return bCircle(x_, y_, r_);
}