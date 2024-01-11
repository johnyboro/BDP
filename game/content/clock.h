#ifndef CONSISTENT_CLOCK_H
#define CONSISTENT_CLOCK_H

#include <chrono>

class clock {
public:
    clock();
    bool shouldUpdate();

private:
    std::chrono::time_point<std::chrono::steady_clock> lastUpdate;
};

#endif // CONSISTENT_CLOCK_H
