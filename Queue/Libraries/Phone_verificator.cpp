/***********************************************************************
 * Module:  ID_verificator.cpp
 * Author:  USUARIO
 * Modified: miércoles, 27 de mayo de 2020 15:07:22
 * Purpose: Declaration of the class ID_verificator
 ***********************************************************************/

#include "Phone_verificator.h"

#include "To_number.cpp"
#include "Verify_number.cpp"
#include <iostream>
#include <string>
#include <ctype.h>

#pragma once

using namespace std;

/**
 * @brief Phone_verify
 * @param phone 
 * @return bool
*/
bool Phone_verificator::Phone_verify(char* phone){
	if (!is_int_number(phone)) {
		return false;
	}

	string _aux_phone = phone;
	if(_aux_phone.length() != 10){
        return false;
	}

	if (*(phone + 0) != '0') {
		return false;
	}

	if (*(phone + 1) != '9') {
		if (*(phone + 1) != '2') {
			return false;
		}
	}

	return true;
}