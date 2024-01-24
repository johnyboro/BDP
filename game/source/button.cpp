#include "../content/button.h"

button::button(int x, int y, int width, int height, const char* label)
        : x(x), y(y), width(width), height(height), label(label) {
    // Initialize colors for the button
    init_pair(1, COLOR_WHITE, COLOR_BLACK);  // Default state
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);    // Selected state

    isSelected = false;
    window = newwin(height, width, y, x);
}

void button::draw(){
    int color_selection;
    if(isSelected)
        color_selection = 2;
    else
        color_selection = 1;
    wattron(window, COLOR_PAIR(color_selection));
    box(window, 0, 0);
    mvwprintw(window, height/2, width/2 - label.length()/2, label.c_str());
    wattroff(window, COLOR_PAIR(color_selection));
    wrefresh(window);
}

//void button::onSelect() {
//    isSelected = true;
//    wattron(window, COLOR_PAIR(2));
//    box(window, 0, 0);
//    mvwprintw(window, 1, 1, label);
//    wattroff(window, COLOR_PAIR(2));
//    wrefresh(window);
//}

//DEPRECATED FUNCTION
