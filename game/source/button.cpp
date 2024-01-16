#include "../content/button.h"

button::button(const std::string& label, int y, int x)
        : label(label), y(y), x(x) {
    initWindow();
}

button::~button() {
    destroyWindow();
}

void button::initWindow() {
    win = newwin(3, width, y, x);
    keypad(win, TRUE);
}

void button::destroyWindow() {
    delwin(win);
}

void button::display(bool selected) const {
    if (selected) {
        wattron(win, A_REVERSE);
    }

    int labelWidth = label.length();
    box(win, 0, 0);
    mvwprintw(win, 1, (width - labelWidth) / 2, label.c_str());

    if (selected) {
        wattroff(win, A_REVERSE);
    }

    wrefresh(win);
}

bool button::handleInput(int input) {
    // In this example, the button is selected on right arrow press
    return input == KEY_RIGHT;
}

bool button::isSelected() const {
    // You might want to add more sophisticated logic here
    return false;
}
