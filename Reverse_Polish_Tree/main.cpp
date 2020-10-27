/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 25 de julio de 2020 17:16:14
 * @function Main
*/

#include <iostream>
#include <string>

#include "Libraries/Input.cpp"

#include "Reverse_Polish.cpp"
#include "Controller.cpp"

using namespace std;

int main()
{
    Controller _control;
    bool flag = true;
    do {
        _control.menu(&flag);
    } while (flag);
}
