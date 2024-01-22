#include "../content/bCircle.h"

#include <cmath>

bCircle::bCircle(int centerX, int centerY, int radius)
        : centerX_(centerX), centerY_(centerY), radius_(radius) {}

int bCircle::getCenterX() const { return centerX_; }

int bCircle::getCenterY() const { return centerY_; }

int bCircle::getRadius() const { return radius_; }

bool bCircle::intersects(const bCircle& other) const {
    int dx = centerX_ - other.getCenterX();
    int dy = centerY_ - other.getCenterY();
    int distance = static_cast<int>(std::sqrt(dx * dx + dy * dy));
    return distance < radius_ + other.getRadius();
}
