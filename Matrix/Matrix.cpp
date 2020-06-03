/***********************************************************************
 * Module:  Matrix.cpp
 * Author:  USUARIO
 * Modified: lunes, 1 de junio de 2020 15:30:20
 * Purpose: Implementation of the class Matrix
 ***********************************************************************/

#include "Matrix.h"
#include "../Input.cpp"
#include "../To_number.cpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Matrix::create_matrix(int _size, T** matrix)
// Purpose:    Implementation of Matrix::create_matrix(int _size, T** matrix)
// Parameters:
// - _size
// - matrix
// Return:     T
////////////////////////////////////////////////////////////////////////

template<typename T>
T** Matrix::create_matrix(int _size, T** matrix)
{
	T **aux = (T**)malloc(_size * sizeof(T*));
	for (int i = 0; i < _size; i++) {
		*(aux +i) = (T*)malloc(_size*sizeof(T));
	}
	set_cero(_size, aux);
	return aux;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matrix::set_cero(int _size, T** matrix)
// Purpose:    Implementation of Matrix::set_cero(int _size, T** matrix)
// Parameters:
// - _size
// - matrix
// Return:     void
////////////////////////////////////////////////////////////////////////

template<typename T>
void Matrix::set_cero(int _size, T** matrix)
{
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			*(*(matrix + i) + j) = 0;
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Matrix::input_num(T** matrix, string input_text, int _size)
// Purpose:    Implementation of Matrix::input_num(T** matrix, string input_text, int _size)
// Parameters:
// - _size
// - input_text
// - matrix
// Return:     void
////////////////////////////////////////////////////////////////////////

template<typename T>
void Matrix::input_num(T** matrix, string input_text, int _size)
{
    Input input;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			*(*(matrix + i) + j) = to_int(input.input_int_number(input_text));
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Matrix::print_matrix(T** matrix, int _size)
// Purpose:    Implementation of Matrix::print_matrix(T** matrix, int _size)
// Parameters:
// - _size
// - matrix
// Return:     void
////////////////////////////////////////////////////////////////////////

template<typename T>
void Matrix::print_matrix(T** matrix, int _size)
{
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			cout << *(*(matrix + i) + j) << ", ";
		}
		printf("\n");
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Matrix::change_matrix(T** matrix, T** matrix_for_change, int _size)
// Purpose:    Implementation of Matrix::change_matrix(T** matrix, T** matrix_for_change, int _size)
// Parameters:
// - matrix
// - matrix_for_change
// - _size
// Return:     void
////////////////////////////////////////////////////////////////////////

template<typename T>
void Matrix::change_matrix(T** matrix, T** matrix_for_change, int _size)
{
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			*(*(matrix_for_change + i) + j) = *(*(matrix + i) + j);
		}
	}
}

