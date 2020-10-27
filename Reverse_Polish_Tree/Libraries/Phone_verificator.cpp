/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of Phone_verificator
*/

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