/***********************************************************************
 * Module:  Array_dinamic.h
 * Author:  USUARIO
 * Modified: lunes, 1 de junio de 2020 15:30:20
 * Purpose: Declaration of the Array_dinamic
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_Matrix_h)
#define __ObjectOrientedModel_2_Matrix_h

#include <iostream>
using namespace std;

template<typename T>
T* create_array(int _size, T* _array);
template<typename T>
void set_cero(int _size, T* _array);
template<typename T>
void input_num(T* _array, string input_text, int _size);
template<typename T>
void print_array(T* _array, int _size);
template<typename T>
void _sort(T* _array, int _size);

#endif
