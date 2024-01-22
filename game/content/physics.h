#ifndef BDP_PHYSICS_H
#define BDP_PHYSICS_H

class physics {
public:
    physics(int gravity, int drag, int bounciness);

    void applyVelocity(int& position, int velocity);
    void applyGravity(int& velocity);
    void applyDrag(int& velocity);

private:
    int gravity_;
    int drag_;
    int bounciness_;
};

#endif //BDP_PHYSICS_H
