#include "../content/button.h"

button::button(int x, int y, int width, int height, const char* label)
        : x(x), y(y), width(width), height(height), label(label) {
    // Initialize colors for the button
    init_pair(1, COLOR_GREEN, COLOR_BLACK);  // Default state
    init_pair(2, COLOR_RED, COLOR_BLACK);    // Selected state

    window = newwin(height, width, y, x);
}

void button::draw(){
    wattron(window, COLOR_PAIR(1));
    box(window, 0, 0);
    mvwprintw(window, 1, 1, label);
    wattroff(window, COLOR_PAIR(1));
    wrefresh(window);
}

void button::onSelect() {
    wattron(window, COLOR_PAIR(2));
    box(window, 0, 0);
    mvwprintw(window, 1, 1, label);
    wattroff(window, COLOR_PAIR(2));
    wrefresh(window);
}
