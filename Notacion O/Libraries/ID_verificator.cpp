/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of ID_verificator
*/

#include "ID_verificator.h"

#include "To_number.cpp"
#include "Verify_number.cpp"
#include <iostream>
#include <string>
#include <ctype.h>

#pragma once

using namespace std;

/**
 * @brief ID_verify
 * @param ID 
 * @return bool
*/
bool ID_verificator::ID_verify(char* ID){
	if (!is_int_number(ID)) {
		return false;
	}

	string _aux_ID = ID;
	if(_aux_ID.length() != 10){
        return false;
	}

	char* province = (char*)calloc(2, sizeof(char));
	*(province + 0) = *(ID + 0);
	*(province + 0) = *(ID + 1);
	if (!is_between(0, to_int(province), 24)) {
		return false;
	}

	if (!is_between(-1, to_int(*(ID + 2)), 6)) {
		return false;
	}

	if (!check_last_digit(ID)) {
		return false;
	}

	return true;
}

/**
 * @brief is_between
 * @param min 
 * @param number 
 * @param max 
 * @return bool
*/
bool ID_verificator::is_between(int min, int number, int max) {
	return (min < number && number < max);
}

/**
 * @brief next_ten
 * @param number 
 * @return int
*/
int ID_verificator::next_ten(int number) {
	while (number%10) {
		number++;
	}
	return number;
}

/**
 * @brief check_last_digit
 * @param ID 
 * @return bool
*/
bool ID_verificator::check_last_digit(char* ID) {
	int check_number = 0;
	string _aux_ID = ID;
	for (int i = 0; i < _aux_ID.length() - 1; i++) {
		if (i % 2) {
			check_number += to_int(*(ID + i));
		}
		else {
			int number = to_int(*(ID + i)) * 2;
			if (number >= 10) {
				check_number += number - 9;
			}
			else {
				check_number += number;
			}
		}
	}

	if ((next_ten(check_number) - check_number) != to_int(*(ID + 9))) {
		return false;
	}

	return true;
}