/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of Screen
*/

#if !defined(__Screen)
#define __Screen

#include <iostream>

using namespace std;

class Screen {
public:

    const int BLACK = 0;
    const int BLUE = 1;
    const int GREEN = 2;
    const int CYAN = 3;
    const int RED = 4;
    const int MAGENTA = 5;
    const int BROWN = 6;
    const int LIGHT_GRAY = 7;
    const int LIGHT_BLUE = 8;
    const int LIGHT_GREEN = 9;
    const int LIGHT_CYAN = 10;
    const int LIGHT_RED = 11;
    const int LIGHT_MAGENTA = 12;
    const int LIGHT_YELLOW = 13;
    const int YELLOW = 14;
    const int WHITE = 15;

    void gotoxy(int x, int y);
    void hide_cursor();
    void screen_size(int width, int height);
    void color_text(int color);
    //void color_background(int color);
private:
protected:
};

#endif
