#ifndef BUTTON_H
#define BUTTON_H

#include <ncurses.h>
#include <string>

class button {
public:
    button(const std::string& label, int y, int x);
    ~button();

    void display(bool selected) const;
    bool handleInput(int input);
    bool isSelected() const;

private:
    std::string label;
    int y, x;
    static const int width = 20;  // Adjust as needed
    WINDOW *win;

    void initWindow();
    void destroyWindow();
};

#endif // BUTTON_H
