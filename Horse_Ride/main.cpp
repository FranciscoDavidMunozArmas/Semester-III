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
#include "Horse_ride.cpp"
#include "Libraries/Input.h"
#include "Libraries/To_number.cpp"

using namespace std;

int main()
{
    Input _input;
    int _y;
    int _x;

    int _table_size = to_int(_input.input_int_number("Ingrese el tamaño de la tabla: "));

    Horse_ride _horse(_table_size);
    do {
        _x = to_int(_input.input_int_number("Coordenada en X: "));
    } while (_x < 0 || _table_size <= _x);

    do {
        _y = to_int(_input.input_int_number("Coordenada en Y: "));
    } while (_y < 0 || _table_size <= _y);

    _horse._init_position(_x,_y);
    _horse._start();
}
