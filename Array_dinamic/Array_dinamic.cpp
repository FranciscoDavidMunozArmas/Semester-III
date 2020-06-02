/***********************************************************************
 * Module:  Array_dinamic.cpp
 * Author:  USUARIO
 * Modified: lunes, 1 de junio de 2020 15:30:20
 * Purpose: Implementation of the Array_dinamic
 ***********************************************************************/

#include "Array_dinamic.h"
#include "../Input.cpp"
#include "../To_number.cpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       create_array(int _size, T* _array)
// Purpose:    Implementation of create_array(int _size, T* _array)
// Parameters:
// - _array
// - _size
// Return:     T
////////////////////////////////////////////////////////////////////////

template<typename T>
T* create_array(int _size, T* _array)
{
	T *aux = (T*)malloc(_size * sizeof(T));
	set_cero(_size, aux);
	return aux;
}

////////////////////////////////////////////////////////////////////////
// Name:       set_cero(int _size, T* _array)
// Purpose:    Implementation of set_cero(int _size, T* _array)
// Parameters:
// - _array
// - _size
// Return:     void
////////////////////////////////////////////////////////////////////////

template<typename T>
void set_cero(int _size, T* _array)
{
	for (int i = 0; i < _size; i++) {
		*(_array + i) = 0;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       input_num(T* _array, string input_text, int _size)
// Purpose:    Implementation of input_num(T* _array, string input_text, int _size)
// Parameters:
// - _array
// - _size
// Return:     void
////////////////////////////////////////////////////////////////////////

template<typename T>
void input_num(T* _array, string input_text, int _size)
{
    Input input;
	for (int i = 0; i < _size; i++) {
		*(_array + i) = to_int(input.input_int_number(input_text));
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       print_array(T* _array, int _size)
// Purpose:    Implementation of print_array(T* _array, int _size)
// Parameters:
// - _array
// - _size
// Return:     void
////////////////////////////////////////////////////////////////////////

template<typename T>
void print_array(T* _array, int _size)
{
	for (int i = 0; i < _size; i++) {
		cout << *(_array + i) << ", ";
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       sort(T* _array, int _size)
// Purpose:    Implementation of sort(T* _array, int _size)
// Parameters:
// - _array
// - _size
// Return:     void
////////////////////////////////////////////////////////////////////////
template<typename T>
void _sort(T* _array, int _size)
{
	T aux;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			if (j != _size -1) {
				if (*(_array + j + 1) < *(_array + j)) {
					aux = *(_array + j + 1);
					*(_array + j + 1) = *(_array + j);
					*(_array + j) = aux;
				}
			}
		}
	}
}
