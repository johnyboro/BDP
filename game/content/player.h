#ifndef BDP_PLAYER_H
#define BDP_PLAYER_H

#include "physics.h"

class player {
public:
    player(int x, int y, int initialVelocityX = 0, int initialVelocityY = 0);

    // Getter methods
    int getX() const;
    int getY() const;
    int getVelocityX() const;
    int getVelocityY() const;

    // Setter methods
    void setX(int x);
    void setY(int y);
    void setVelocityX(int velocityX);
    void setVelocityY(int velocityY);

    // Update player position based on velocity
    void update();

    // Draw the player on the screen
    void draw() const;

private:
    int x_;             // player x-coordinate
    int y_;             // player y-coordinate
    int velocityX_;     // player velocity in the x-direction
    int velocityY_;     // player velocity in the y-direction
    physics physics_;
};

#endif //BDP_PLAYER_H
