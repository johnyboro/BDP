#ifndef BDP_PLAYER_H
#define BDP_PLAYER_H

#include "physics.h"
#include "bCircle.h"

#include <vector>
#include <string>

class player {
public:
    player(int id, int x, int y, int team, int initialVelocityX = 0, int initialVelocityY = 0, int speed = 2,
           int gravity = -9, int drag = 10, int bounciness = 1, int r = 10, const char* ch = "X");

    // Getter methods
    int getX() const;
    int getY() const;
    int getVelocityX() const;
    int getVelocityY() const;
    int getTeam() const;
    int getId() const;

    // Setter methods
    void setX(int x);
    void setY(int y);
    void setVelocityX(int velocityX);
    void setVelocityY(int velocityY);

    void handleInput(int input);
    void update();

    void initCircle();

    void draw() const;

    bCircle getBoundingCircle() const;

private:
    int id_;
    int x_;
    int y_;
    int velocityX_;
    int velocityY_;
    int speed_;
    int gravity_;
    int drag_;
    int bounciness_;
    int r_;             // player radius
    const char* ch_;           // player symbol
    int team_;
    physics physics_;
    std::vector<std::pair<int, int>> circlePositions_;  // Precomputed circle positions
};

#endif //BDP_PLAYER_H
