/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of Array_Dynamic
*/

#include "Array_dinamic.h"
#include "Input.cpp"
#include "To_number.cpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#pragma once

using namespace std;

/**
 * @brief _create_array
 * @tparam T
 * @param _size
 * @param _array
 * @return T
*/
template<typename T>
T* Array_dynamic::_create_array(int _size, T* _array)
{
	T *aux = (T*)malloc(_size * sizeof(T));
	_set_cero(aux);
	return aux;
}

/**
 * @brief _set_cero
 * @tparam T
 * @param _array
*/
template<typename T>
void Array_dynamic::_set_cero(T* _array)
{
	int _size = _dynamic_size(_array);
	for (int i = 0; i < _size; i++) {
		*(_array + i) = 0;
	}
}

/**
 * @brief _dynamic_size
 * @tparam T
 * @param _array
 * @return int
*/
template<typename T>
int Array_dynamic::_dynamic_size(T* _array){
	return _msize((void*)_array)/sizeof(T);
}

/**
 * @brief _resize
 * @tparam T
 * @param _array
 * @param _new_size
 * @return T
*/
template<typename T>
T* Array_dynamic::_resize(T* _array, int _new_size) {
	T* _aux_array;
	_aux_array = (T*)realloc(_array, sizeof(T)*_new_size);
	return _aux_array;
}
