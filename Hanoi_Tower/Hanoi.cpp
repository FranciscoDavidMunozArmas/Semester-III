/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 20 de julio de 2020 10:07:14
 * @function Implementation of Hanoi
*/

#include <iostream>
#include <ctime>
#include <iostream>
#include "Libraries/Input.cpp"
#include "Libraries/To_number.cpp"

#include "Hanoi.h"

using namespace std;

/**
 * @brief Hanoi
 * @return 
*/
Hanoi::Hanoi() {}

/**
 * @brief start
*/
void Hanoi::start(char _tower_A, char _tower_B, char _tower_C) {
    Input _input;
    int _num = to_int(_input.input_int_number("Ingrese el numero de discos: "));
    cout << "El numero de movimientos a realizar es: " << calculate(_num) << endl;
    system("pause");
    system("cls");
    this->_do_movements(_num, _tower_A, _tower_C, _tower_B);
}

/**
 * @brief calculate
 * @param _num 
 * @return int
*/
int Hanoi::calculate(int _num) {
    if (_num == 1) {
        return 1;
    }
    else {
        return 2 * calculate(_num - 1) + 1;
    }
}

/**
 * @brief _do_movements
 * @param _num
 * @param _tower_A
 * @param _tower_B
 * @param _tower_C
*/
void Hanoi::_do_movements(int _num, char _tower_A, char _tower_C, char _tower_B) {
    if (_num == 1) {
        _print_message(_num, _tower_A, _tower_C);
    }
    else {
        _do_movements(_num - 1, _tower_A, _tower_B, _tower_C);
        _print_message(_num, _tower_A, _tower_C);
        _do_movements(_num - 1, _tower_B, _tower_C, _tower_A);
    }
}

/**
 * @brief _print_message
 * @param _num
 * @param _A
 * @param _B
*/
void Hanoi::_print_message(int _num, char _A, char _B) {
    cout << "El disco " << _num << " se mueve de la torre " << _A << " hasta la torre " << _B << endl;
}

/**
 * @brief ~Hanoi
 * @return 
*/
Hanoi::~Hanoi() {}
