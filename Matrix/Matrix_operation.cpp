/***********************************************************************
 * Module:  Matrix_operation.cpp
 * Author:  USUARIO
 * Modified: lunes, 1 de junio de 2020 15:32:38
 * Purpose: Implementation of the class Matrix_operation
 ***********************************************************************/

#include "Matrix_operation.h"
#include "Matrix.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Matrix_operation::add(T** matrix, T** matrix_2, T** matrix_r, int _size)
// Purpose:    Implementation of Matrix_operation::add(T** matrix, T** matrix_2, T** matrix_r, int _size)
// Parameters:
// - matrix
// - _size
// Return:     void
////////////////////////////////////////////////////////////////////////

template<typename T>
void Matrix_operation::add(T** matrix, T** matrix_2, T** matrix_r, int _size)
{
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			for (int h = 0; h < _size; h++) {
				*(*(matrix_r + i) + j) = (*(matrix + i) + j) + *(*(matrix_2 + i) + j);
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Matrix_operation::substract(T** matrix, T** matrix_2, T** matrix_r, int _size)
// Purpose:    Implementation of Matrix_operation::substract(T** matrix, T** matrix_2, T** matrix_r, int _size)
// Parameters:
// - matrix
// - matrix_2
// - matrix_r
// - _size
// Return:     void
////////////////////////////////////////////////////////////////////////

template<typename T>
void Matrix_operation::substract(T** matrix, T** matrix_2, T** matrix_r, int _size)
{
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			for (int h = 0; h < _size; h++) {
				*(*(matrix_r + i) + j) = (*(matrix + i) + j) - *(*(matrix_2 + i) + j);
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Matrix_operation::multiply(T** matrix, T** matrix_2, T** matrix_r, int _size)
// Purpose:    Implementation of Matrix_operation::multiply(T** matrix, T** matrix_2, T** matrix_r, int _size)
// Parameters:
// - matrix
// - matrix_2
// - matrix_r
// - _size
// Return:     void
////////////////////////////////////////////////////////////////////////

template<typename T>
void Matrix_operation::multiply(T** matrix, T** matrix_2, T** matrix_r, int _size)
{
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			for (int h = 0; h < _size; h++) {
				*(*(matrix_r + i) + j) += *(*(matrix + j) + h) * *(*(matrix_2 + h) + i);
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Matrix_operation::pow(T** matrix, int _size, int index)
// Purpose:    Implementation of Matrix_operation::pow(T** matrix, int _size, int index)
// Parameters:
// - matrix
// - _size
// Return:     void
////////////////////////////////////////////////////////////////////////

template<typename T>
void Matrix_operation::pow(T** matrix, int _size, int index)
{
    Matrix m;
	T** aux;
	aux = m.create_matrix(_size, aux);
	T** matrix_r;
	matrix_r = m.create_matrix(_size, matrix_r);

	for (int times = 0; times < index - 1; times++) {
		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++) {
				for (int h = 0; h < _size; h++) {
					if (times == 0) {
						*(*(matrix_r + i) + j) += *(*(matrix + j) + h) * *(*(matrix + h) + j);
					}
					else {
						*(*(matrix_r + i) + j) += *(*(matrix + j) + h) * *(*(aux + h) + j);
					}
				}
			}
		}

		m.change_matrix(matrix_r, aux, _size);
		m.set_cero(_size, matrix_r);
	}
	m.change_matrix(aux, matrix, _size);
}
