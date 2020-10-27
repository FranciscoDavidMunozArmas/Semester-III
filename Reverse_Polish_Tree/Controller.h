/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 25 de julio de 2020 17:16:14
 * @function Declaration of Controller
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

using namespace std;

class Controller
{
public:
    Controller();
    void menu(bool* flag);
    int _option();
    virtual ~Controller();
protected:
private:
};

#endif
