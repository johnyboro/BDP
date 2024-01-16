#ifndef TERMINAL_SIZE_CHECKER_H
#define TERMINAL_SIZE_CHECKER_H

class terminalSize {
public:
    terminalSize(int desiredRows, int desiredCols);
    ~terminalSize();

    bool isTerminalSizeAchieved();
    void waitForTerminalSize();

private:
    int desiredRows;
    int desiredCols;
    int currentRows;
    int currentCols;
};

#endif // TERMINAL_SIZE_CHECKER_H
