/***********************************************************************
 * Module:  Verify_number.cpp
 * Author:  USUARIO
 * Modified: miércoles, 27 de mayo de 2020 15:07:22
 * Purpose: Declaration of the class Verify_number
 ***********************************************************************/
#define _GLIBCXX_USE_CXX11_ABI 0

#include "Verify_number.h"

#include <iostream>
#include <string>
#include <ctype.h>

#pragma once

using namespace std;

/**
 * @brief is_int_number
 * @param string_1 
 * @return bool
*/
bool is_int_number(string string_1) {
	for (char aux: string_1) {
		if (!isdigit(aux)) {
			return false;
			break;
		}
	}
	return true;
}

/**
 * @brief is_float_number
 * @param string_1 
 * @return bool
*/
bool is_float_number(string string_1) {
	for (char aux : string_1) {
		if (!isdigit(aux) && aux != '.') {
			return false;
			break;
		}
	}
	return true;
}
