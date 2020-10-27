/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Implementation of Sudoku
*/

#include <iostream>
#include <string>
#include <ctime>

#include "Sudoku.h"

#define MAX 35

using namespace std;

/**
 * @brief _init
 * @param _size 
 * @return int**
*/
int** Sudoku::_init(int _size) {
    matriz = (int**)malloc(sizeof(int*) * _size);
    for (int i = 0; i < _size; i++) {
        *(matriz + i) = (int*)malloc(sizeof(int*) * _size);
    }
    return matriz;
}

/**
        @brief _control_iterations
        @param num, _size, _cont1, _cont2, **matriz
        @return int
 */
int Sudoku::_control_iterations(int num, int _size, int _cont1, int _cont2, int** matriz) {
    _cont_stop = 0;
    for (int i = 0; (i < _size && _cont_stop == 0); i++) {
        if (*(*(matriz + _cont1) + i) == num || *(*(matriz + i) + _cont2) == num) {
            _cont_stop = 1;
        }
    }
    return _cont_stop;
}

/**
        @brief _fill
        @param **matriz
        @return int**
 */
int** Sudoku::_fill(int** matriz) {
    srand(time(NULL));
    do {
        _cont2 = 0;
        matriz = _init(10);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                *(*(matriz + i) + j) = 0;
                _cont1 = 0;
                _verify_movements(i, j);
                *(*(matriz + i) + j) = num_random;
                _cont2++;
            }
        }
    } while (_cont2 != 81);
    return matriz;
}

/**
        @brief _verify_movements
        @param i, j
 */
void Sudoku::_verify_movements(int i, int j) {
    do {
        num_random = rand() % 9 + 1;
        _cont_stop = _control_iterations(num_random, 9, i, j, matriz);
        _cont1++;
        if (_cont1 > 15) {
            i = 9;
            j = 9;
        }
    } while (_cont_stop == 1);
}

/**
 * @brief _cuadrante
 * @param mat 
 * @param fila 
 * @param columna 
 * @param numero 
 * @return bool
*/
bool Sudoku::_cuadrante(int** mat, int fila, int columna, int numero) {
    int filaCuadrante = 0;
    int columnaCuadrante = 0;
    if (fila >= 3 && fila <= 5)
        filaCuadrante = 3;
    if (fila >= 6 && fila <= 8)
        filaCuadrante = 6;

    if (columna >= 3 && columna <= 5)
        columnaCuadrante = 3;
    if (columna >= 6 && columna <= 8)
        columnaCuadrante = 6;

    for (int i = filaCuadrante; i < filaCuadrante + 3; i++)
    {
        for (int j = columnaCuadrante; j < columnaCuadrante + 3; j++)
        {
            if (*(*(mat + i) + j) == numero)
                return true;
        }
    }

    return false;
}

/**
        @brief _print_sudoku
        @param **matriz
 */
void Sudoku::_print_sudoku(int** matriz) {
    _print();
    for (int i = 0; i < 9; i++) {
        cout << "\n";
        if (i == 3 || i == 6) {
            _print();
            cout << "\n";
        }
        for (int j = 0; j < 9; j++) {
            if (j == 3 || j == 6) {
                cout << "   |";
            }
            cout << " " << *(*(matriz + i) + j) << " ";
        }
        printf("| ");
    }
    cout << "\n";
    _print();
}

/**
        @brief _print
 */
void Sudoku::_print() {
    for (int i = 0; i < MAX; i++) {
        cout << "-";
    }
}

/**
 * @brief resolver_sudoku
*/
void Sudoku::resolver_sudoku() {
    int** matriz;
    matriz = _fill(matriz);
    _print_sudoku(matriz);
}

/**
 * @brief ~Sudoku
 * @return 
*/
Sudoku::~Sudoku() {}
