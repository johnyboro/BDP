#include "../content/gameClock.h"

gameClock::gameClock(int tick) : lastUpdate(), tick(tick), running(true) {}
gameClock::~gameClock() {
    gameClock::stopClock();
}

void gameClock::startClock() {
    if (!running) {
        lastUpdate = std::chrono::steady_clock::now();
        running = true;
    }
}

void gameClock::stopClock() {
    if (running) {
        lastUpdate = std::chrono::steady_clock::now();
        running = false;
    }
}

bool gameClock::shouldUpdate() {
    if (!running) {
        return false;
    }

    auto now = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(now - lastUpdate);

    if (duration.count() >= 1.0 / tick) {
        lastUpdate = now;  // Update lastUpdate to the current time
        return true;
    }

    return false;
}
