/***********************************************************************
 * Module:  Array.cpp
 * Author:  USUARIO
 * Modified: jueves, 28 de mayo de 2020 19:07:11
 * Purpose: Implementation of the class Array
 ***********************************************************************/

#include "Array.h"

#include "Input.cpp"
#include "To_number.cpp"
#include "InstanceOf.cpp"

using namespace std;

/**
 * @brief set_cero
 * @tparam T 
 * @param r 
*/
template<class T, int _size>
void set_cero(T(&r)[_size])
{
	for (int i = 0; i < _size; i++) {
		r[i] = 0;
	}
}

/**
 * @brief input
 * @tparam T 
 * @param _input_phrase 
 * @param r 
*/
template<class T, int _size>
void input(char* _input_phrase, T(&r)[_size])
{
	for (int i = 0; i < _size; i++) {
		string aux = Input::input_only_numbers(_input_phrase);
		r[i] = to_int(aux);
	}

}

/**
 * @brief process
 * @tparam T 
 * @param r 
 * @param number 
*/
template<class T, int _size>
void process(T(&r)[_size], int number)
{
	for (int i = 0; i < _size; i++) {
		r[i] *= number;
	}
}

/**
 * @brief print_array
 * @tparam T 
 * @param r 
*/
template<class T, int _size>
void print_array(T(&r)[_size])
{
	for (int i = 0; i < _size; i++) {
		cout << r[i] << endl;
	}
}

/**
 * @brief _size
 * @tparam T 
 * @param r 
 * @return int
*/
template<class T, int N>
int _size(T(&r)[N])
{
	return N;
}
