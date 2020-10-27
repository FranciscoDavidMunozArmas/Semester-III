/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Implementation of Queen
*/

#include "Queen.h"

#include "Libraries/Matrix.cpp"

/**
 * @brief Queen
 * @return 
*/
Queen::Queen() {
    this->_size = 8;
    this->_queens = _size;
    _table = _matrix.create_matrix(_table, _size);
}

/**
 * @brief Queen
 * @param _size 
 * @return 
*/
Queen::Queen(int _size) {
    this->_size = _size;
    this->_queens = _size;
    _table = _matrix.create_matrix(_table, _size);
}

/**
 * @brief _solve
 * @param x 
 * @param y 
 * @param _number 
 * @param solutions 
 * @param _unique 
*/
void Queen::_solve(int x, int y, int _number, int* solutions, int* _unique) {
    for (int i = 0; i < _queens; i++) {
        if (_number == _queens) {
            if (_is_solve()) {
                *_unique += 1;
                if (*_unique == 1) {
                    *solutions += 1;
                    cout << "Solucion: " << *solutions << endl;
                    _print_table();
                }
            }
            break;
        }
        else {
            if (!_find_queen(x, y)) {
                *(*(_table + y) + x) = 1;
                _solve(i, y + 1, _number + 1, solutions, _unique);
            }
            else {
                break;
            }
            *(*(_table + y) + x) = 0;
        }
    }
}

/**
 * @brief _is_solve
 * @return bool
*/
bool Queen::_is_solve() {
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if (*(*(_table + i) + j) == 1) {
                if (_find_queen(j, i)) {
                    return false;
                }
            }
        }
    }

    return true;
}

/**
 * @brief _find_queen
 * @param x 
 * @param y 
 * @return bool
*/
bool Queen::_find_queen(int x, int y) {

    for (int i = 0; i < _size; i++) {
        if (*(*(_table + i) + x) == 1 && i != y) {
            return true;
        }
        if (*(*(_table + y) + i) == 1 && i != x) {
            return true;
        }
    }

    int _new_X = x;
    int _new_Y = y;

    while (0 < _new_X && 0 < _new_Y) {
        _new_X--;
        _new_Y--;
    }

    while (_new_X < (_size - 1) && _new_Y < (_size - 1)) {
        if (*(*(_table + _new_Y) + _new_X) == 1 && _new_X != x && _new_Y != y) {
            return true;
        }
        _new_X++;
        _new_Y++;
    }

    _new_X = x;
    _new_Y = y;

    while (0 < _new_X && _new_Y < (_size - 1)) {
        _new_X--;
        _new_Y++;
    }

    while (_new_X < (_size - 1) && 0 < _new_Y) {
        if (*(*(_table + _new_Y) + _new_X) == 1 && _new_X != x && _new_Y != y) {
            return true;
        }
        _new_X++;
        _new_Y--;
    }

    return false;
}

/**
 * @brief _start
*/
void Queen::_start() {
    int solution_count = 0;
    for (int i = 0; i < _size; i++) {
        int _unique = 0;
        _solve(i, 0, 0, &solution_count, &_unique);
    }
    cout << endl << "Numero de soluciones posibles: " << solution_count << endl;
    free(_table);
}

/**
 * @brief _print_table
*/
void Queen::_print_table() {
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if (*(*(_table + i) + j) == 1) {
                cout << "R" << " ";
            }
            else {
                cout << "-" << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * @brief ~Queen
 * @return 
*/
Queen::~Queen() {}
