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
    int options(T* option, int index);
    template<typename T>
    int options(T* option, int index, int color);
    template<typename T>
    int options(char* message ,T* option, int index);
    template<typename T>
    int options(char* message, T* option, int index, int color);

    int yes_no_option(char* message, int color);
    int yes_no_option(char* message);
    int yes_no_option(int color);
    int yes_no_option();
private:
    Screen screen;
protected:
};

#endif
