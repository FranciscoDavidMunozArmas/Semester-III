/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of Math
*/

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