#ifndef BDP_BCIRCLE_H
#define BDP_BCIRCLE_H

class bCircle {
public:
    bCircle(int centerX, int centerY, int radius);

    int getCenterX() const;
    int getCenterY() const;
    int getRadius() const;

    bool intersects(const bCircle& other) const;

private:
    int centerX_;
    int centerY_;
    int radius_;
};

#endif //BDP_BCIRCLE_H
