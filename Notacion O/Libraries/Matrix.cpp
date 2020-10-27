/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Declaration of Matrix
*/

#include "Matrix.h"
#include "Array_dinamic.cpp"

#pragma once;

/**
 * @brief Matrix
 * @return
*/
Matrix::Matrix() {}

/**
 * @brief create_matrix
 * @tparam T
 * @param _matrix
 * @param size
 * @return T
*/
template<typename T>
T** Matrix::create_matrix(T** _matrix, int _size) {
	T** aux = (T**)malloc(_size*sizeof(T*));
	for (int i = 0; i < _size; i++) {
		*(aux + i) = (T*)malloc(_size * sizeof(T));
	}
	return set_cero(aux);
}

/**
 * @brief create_matrix
 * @tparam T
 * @param _matrix
 * @param width
 * @param height
 * @return T
*/
template<typename T>
T** Matrix::create_matrix(T** _matrix, int width, int height) {
	T** aux = (T**)malloc(height * sizeof(T*));
	for (int i = 0; i < width; i++) {
		*(aux + i) = (T*)malloc(width * sizeof(T));
	}
	return set_cero(aux);
}

/**
 * @brief set_cero
 * @tparam T
 * @param _matrix
 * @return T
*/
template<typename T>
T** Matrix::set_cero(T** _matrix) {
	for (int i = 0; i < _ad._dynamic_size(_matrix); i++) {
		for (int j = 0; j < _ad._dynamic_size(*(_matrix + i)); j++) {
			*(*(_matrix + i) + j) = NULL;
		}
	}

	return _matrix;
}

/**
 * @brief _print_matrix
 * @tparam T
 * @param _matrix
*/
template<typename T>
void Matrix::_print_matrix(T** _matrix) {
	for (int i = 0; i < _ad._dynamic_size(_matrix); i++) {
		for (int j = 0; j < _ad._dynamic_size(*(_matrix + i)); j++) {
			cout << *(*(_matrix + i) + j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/**
 * @brief ~Matrix
 * @return
*/
Matrix::~Matrix() {}
