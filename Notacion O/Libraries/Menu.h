/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of Menu
*/

#if !defined(__Menu)
#define __Menu

#include <iostream>
#include "Screen.h"

using namespace std;

class Menu {
public:
    template<typename T>
    int options_vetical(T* option, int index, int x, int y);
    template<typename T>
    int options_horizontal(T* option, int index, int x, int y);
private:
    Screen screen;
protected:
};

#endif
