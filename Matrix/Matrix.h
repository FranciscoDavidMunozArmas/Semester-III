/***********************************************************************
 * Module:  Matrix.h
 * Author:  USUARIO
 * Modified: lunes, 1 de junio de 2020 15:30:20
 * Purpose: Declaration of the class Matrix
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_Matrix_h)
#define __ObjectOrientedModel_2_Matrix_h

#include <iostream>
using namespace std;

class Matrix {
public:
	template<typename T>
	T** create_matrix(int _size, T** matrix);
	template<typename T>
	void set_cero(int _size, T** matrix);
	template<typename T>
	void input_num(T** matrix, string input_text, int _size);
	template<typename T>
	void print_matrix(T** matrix, int _size);
	template<typename T>
	void change_matrix(T** matrix, T** matrix_for_change, int _size);
};

#endif
