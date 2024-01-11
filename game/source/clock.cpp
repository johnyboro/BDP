#include "../content/clock.h"

clock::clock() : lastUpdate(std::chrono::steady_clock::now()) {}

bool clock::shouldUpdate() {
    auto now = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(now - lastUpdate);

    if (duration.count() >= 1.0 / 60.0) {
        lastUpdate = now;
        return true;
    }

    return false;
}
