/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Main
*/

#include <iostream>

#include "Regiones.cpp"
#include "Ingreso.cpp"
#include "Sudoku.cpp"

using namespace std;

int main()
{
    Regiones reg;
    Sudoku sud;
    reg.iniciar();
    sud.resolver_sudoku();
}
