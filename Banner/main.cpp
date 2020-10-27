/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 20 de junio de 2020 10:07:14
 * @function Main
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

#include "Libraries/Banner.cpp"
#include "Libraries/Screen.cpp"
#include "Libraries/Array_dinamic.cpp"
#include "Libraries/Input.cpp"

using namespace std;

int main ()
{
    Input _input;
	Screen screen;
	Banner _banner;
	screen.hide_cursor();
    _banner._banner_right_left("Banner style 1", 0, 0);
    _banner._banner_right_left_left_right("Banner style 2", 0, 0);
    _banner._banner_left_right("Banner style 3", 0, 0);
}
