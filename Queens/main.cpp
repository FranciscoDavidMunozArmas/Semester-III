/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Main
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Libraries/Input.h"
#include "Libraries/To_number.cpp"

#include "Queen.cpp"

using namespace std;

int main()
{
    Input _input;
    int _size;
    do {
        _size = to_int(_input.input_int_number("Introduzca el tamaño del tablero: "));
    } while (_size < 4 || 10 < _size);
    cout << endl;

    Queen _q(_size);
    _q._start();
}
