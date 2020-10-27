/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 20 de julio de 2020 10:07:14
 * @function Declaration of Hanoi
*/

#ifndef HANOI_H
#define HANOI_H

#include <iostream>

using namespace std;

class Hanoi
{
public:
    Hanoi();
    void start(char _tower_A, char _tower_B, char _tower_C);
    int calculate(int _num);
    void _do_movements(int _num, char _tower_A, char _tower_C, char _tower_B);
    void _print_message(int _num, char _A, char _B);
    virtual ~Hanoi();
protected:
private:
};

#endif // HANOI_H
