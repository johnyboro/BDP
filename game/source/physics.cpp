#include "../content/physics.h"

physics::physics(int gravity, int drag, int bounciness) : gravity_(gravity), drag_(drag), bounciness_(bounciness) {}


void physics::applyVelocity(int& position, int velocity) {
    position += velocity;
}

void physics::applyGravity(int& velocity) {
    velocity += gravity_;
}

void physics::applyDrag(int& velocity) {
    if (velocity > 0) {
        velocity -= drag_;
        if (velocity < 0) {
            velocity = 0;
        }
    } else if (velocity < 0) {
        velocity += drag_;
        if (velocity > 0) {
            velocity = 0;
        }
    }
}

