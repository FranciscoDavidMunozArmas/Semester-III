/***********************************************************************
 * Module:  Matrix_operation.h
 * Author:  USUARIO
 * Modified: lunes, 1 de junio de 2020 15:32:38
 * Purpose: Declaration of the class Matrix_operation
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_Matrix_operation_h)
#define __ObjectOrientedModel_2_Matrix_operation_h

#include <iostream>
using namespace std;

class Matrix_operation {
public:
	template<typename T>
	void add(T** matrix, T** matrix_2, T** matrix_r, int _size);
	template<typename T>
	void substract(T** matrix, T** matrix_2, T** matrix_r, int _size);
	template<typename T>
	void multiply(T** matrix, T** matrix_2, T** matrix_r, int _size);
	template<typename T>
	void pow(T** matrix, int _size, int index);
};


#endif
