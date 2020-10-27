/***********************************************************************
 * Module:  Array_dinamic.h
 * Author:  USUARIO
 * Modified: lunes, 1 de junio de 2020 15:30:20
 * Purpose: Declaration of the class Array_dinamic
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_Matrix_h)
#define __ObjectOrientedModel_2_Matrix_h

#include <iostream>
using namespace std;

class Array_dynamic {
public:
	template<typename T>
	T* _create_array(int _size, T* _array);
	template<typename T>
	void _set_cero(T* _array);
	template<typename T>
	void _input_string(T* _array, string input_text);
	template<typename T>
	void _input_num(T* _array, string input_text);
	template<typename T>
	void _print_array(T* _array);
	template<typename T>
	void _sort(T* _array);
	template<typename T>
	int _dynamic_size(T* _array);
};

#endif
