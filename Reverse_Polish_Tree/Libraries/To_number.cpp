/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of To_Number
*/

#define _GLIBCXX_USE_CXX11_ABI 0

#include "To_number.h"

#include <iostream>
#include <string>
#include <ctype.h>

#pragma once

using namespace std;

/**
 * @brief to_int
 * @param num 
 * @return int
*/
int to_int(char* num) {
	return atoi(num);
}

/**
 * @brief to_int
 * @param num 
 * @return int
*/
int to_int(char num) {
	return num - '0';
}

/**
 * @brief to_int
 * @param num 
 * @return int
*/
int to_int(string num) {
	return stoi(num);
}

/**
 * @brief to_float
 * @param num 
 * @return float
*/
float to_float(char* num) {
	return atof(num);
}

/**
 * @brief to_float
 * @param num 
 * @return float
*/
float to_float(string num) {
	return stof(num);
}

/**
 * @brief to_double
 * @param num 
 * @return double
*/
double to_double(char* num) {
	return atol(num);
}

/**
 * @brief to_double
 * @param num 
 * @return double
*/
double to_double(std::string num) {
	return stod(num);
}