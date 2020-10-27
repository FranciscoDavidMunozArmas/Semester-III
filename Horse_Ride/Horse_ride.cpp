/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Implementation of Horse_ride
*/

#include "Horse_ride.h"
#include "Libraries/Matrix.cpp"

/**
 * @brief Horse_ride
 * @return
*/
Horse_ride::Horse_ride() {
	this->_startX = 0;
	this->_startY = 0;
	this->_size = 8;
    this->_movement = _horse_move();
    this->table = _matrix.create_matrix(table, _size);
}

/**
 * @brief Horse_ride
 * @param _table_size
 * @return
*/
Horse_ride::Horse_ride(int _table_size) {
    this->_startX = 0;
    this->_startY = 0;
    this->_size = _table_size;
    this->_movement = _horse_move();
    this->table = _matrix.create_matrix(table, _size);
}

/**
 * @brief _init_position
 * @param x
 * @param y
*/
void Horse_ride::_init_position(int x, int y) {
    if (x < 0) {
        x = 0;
    }
    else if ((_size - 1) < x) {
        x = _size;
    }

    if (y < 0 || (_size - 1) < y) {
        y = 0;
    }
    else if ((_size - 1) < y) {
        y = _size;
    }

    this->_startX = x;
    this->_startY = y;
    *(*(table + y) + x) = 1;
}

/**
 * @brief _jump
 * @param x
 * @param y
 * @param _jump
 * @param _solution
 * @param _pos
*/
void Horse_ride::_jump(int x, int y, int _jump_index, int _solution, int _pos, int* _total_sol) {
    for (int i = 0; i < 8; i++) {
        _pos = _get_next_position(x, y, i);
        if (_pos > -1) {
            *(*(table + (int)(_pos % _size)) + (int)(_pos / _size)) = _jump_index;
            if (_jump_index == _size*_size) {
                _solution++;
                if (_solution == 1) {
                    *_total_sol += 1;
                    _print_table();
                }
            }
            _jump((int)(_pos / _size), (int)(_pos % _size), _jump_index + 1, 0, 0, _total_sol);
            *(*(table + (int)(_pos % _size)) + (int)(_pos / _size)) = 0;
        }
    }
}

/**
 * @brief _start
*/
void Horse_ride::_start() {
    int _solution = 0;
    if (_size > 7) {
        cout << "El numero de resultados sera astronomico " << endl << "No se puede realizar por el momento la operacion..." << endl;
        free(table);
        exit(0);
    }
    for (int i = 0; i < 8; i++) {
        int aux = _get_next_position(_startX, _startY, i);
        if (aux > -1) {
            _jump(_startX, _startY, 2, 0, 0, &_solution);
        }
    }
    cout << "Soluciones totales: " << _solution << endl;

    free(table);
}

/**
 * @brief _print_table
*/
void Horse_ride::_print_table() {
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if (*(*(table + i) + j) < 10) {
                cout << "0" << *(*(table + i) + j) << " ";
            }
            else {
                cout << *(*(table + i) + j) << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * @brief _get_next_position
 * @param x
 * @param y
 * @param _move
 * @return int
*/
int Horse_ride::_get_next_position(int x, int y, int _move) {
    int _next_X = x + *(*(_movement + _move) + 0);
    int _next_Y = y + *(*(_movement + _move) + 1);

    if ((0 <= _next_X && _next_X < _size)&&(0 <= _next_Y && _next_Y < _size)&&(*(*(table + _next_Y) + _next_X) == 0)) {
        return _next_X * _size + _next_Y;
    }

    return -1;
}

/**
 * @brief _horse_move
 * @return int**
*/
int** Horse_ride::_horse_move() {
	int** _move = (int**)malloc(8*sizeof(int*));
	for (int i = 0; i < 8; i++) {
		*(_move + i) = (int*)malloc(2 * sizeof(int));
	}

    *(*(_move + 0) + 0) = -2;
    *(*(_move + 0) + 1) = -1;

    *(*(_move + 1) + 0) = -2;
    *(*(_move + 1) + 1) = 1;

    *(*(_move + 2) + 0) = 2;
    *(*(_move + 2) + 1) = -1;

    *(*(_move + 3) + 0) = 2;
    *(*(_move + 3) + 1) = 1;

    *(*(_move + 4) + 0) = -1;
    *(*(_move + 4) + 1) = -2;

    *(*(_move + 5) + 0) = -1;
    *(*(_move + 5) + 1) = 2;

    *(*(_move + 6) + 0) = 1;
    *(*(_move + 6) + 1) = -2;

    *(*(_move + 7) + 0) = 1;
    *(*(_move + 7) + 1) = 2;

    return _move;
}

/**
 * @brief Horse_ride
 * @return
*/
Horse_ride::~Horse_ride() {}
