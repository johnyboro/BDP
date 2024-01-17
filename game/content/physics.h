#ifndef BDP_PHYSICS_H
#define BDP_PHYSICS_H

class physics {
public:
    physics(double gravity = 0.0);

    // Update object position based on velocity and gravity
    void updatePosition(int& x, int& y, int& velocityX, int& velocityY);

private:
    double gravity_; // Gravity acceleration
};

#endif //BDP_PHYSICS_H
