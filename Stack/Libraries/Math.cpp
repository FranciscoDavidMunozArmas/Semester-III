/***********************************************************************
 * Module:  Math.cpp
 * Author:  USUARIO
 * Modified: martes, 2 de junio de 2020 15:47:09
 * Purpose: Implementation of the class Math
 ***********************************************************************/

#include "Math.h"

/**
 * @brief pow
 * @tparam T 
 * @param base 
 * @param index 
 * @return double
*/
template<typename T>
double Math::pow(T base, int index)
{
	if (index == 0) {
		return 1;
	}
	else if (index < 0){
		return pow(base, index + 1) / base;
	}
	else {
		return base * pow(base, index - 1);
	}
}

/**
 * @brief factorial
 * @param base 
 * @return int
*/
int Math::factorial(int base)
{
	if (base <= 1) {
		return 1;
	}
	else {
		return base * factorial(base - 1);
	}
}

/**
 * @brief _abs
 * @tparam T 
 * @param _num 
 * @return T
*/
template<typename T>
T Math::_abs(T _num) {
	return (_num < 0) ? -_num : _num;
}