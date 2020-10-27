/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Main
*/

#include <iostream>

#include "Input_Byte.cpp"

using namespace std;

int main()
{
    char a = 'a';
    system("pause");
    Input_Byte _input;
    string _aux = _input._input("Introduzca: ");
    cout << endl << _aux << endl;
    system("pause");
}
