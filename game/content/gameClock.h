#ifndef CONSISTENT_CLOCK_H
#define CONSISTENT_CLOCK_H

#include <chrono>

class gameClock {
public:
    explicit gameClock(int tick);
    ~gameClock();

    void startClock();  // start the clock
    void stopClock();   // stop the clock
    bool shouldUpdate(); // for logic

private:
    int tick;
    std::chrono::time_point<std::chrono::steady_clock> lastUpdate;
    bool running;  // Flag to indicate if the clock is running
};

#endif // CONSISTENT_CLOCK_H
