#include "../content/physics.h"

physics::physics(double gravity) : gravity_(gravity) {}

void physics::updatePosition(int& x, int& y, int& velocityX, int& velocityY) {
    // Update position based on velocity
    x += velocityX;
    y += velocityY;

    // Apply gravity
    velocityY += gravity_;
}
