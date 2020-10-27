/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of InstanceOfString
*/

#include <iostream>
#include <typeinfo>
#include "InstanceOf.h"

using namespace std;

/**
 * @brief intanceOfString
 * @tparam T 
 * @param var 
 * @return bool
*/
template<typename T>
bool intanceOfString(T var) {
	return typeid(string).name() == typeid(var).name();
}

/**
 * @brief instanceOfInt
 * @tparam T 
 * @param var 
 * @return bool
*/
template<typename T>
bool instanceOfInt(T var) {
	return typeid(int).name() == typeid(var).name();
}

/**
 * @brief instanceOfFloat
 * @tparam T 
 * @param var 
 * @return bool
*/
template<typename T>
bool instanceOfFloat(T var) {
	return typeid(float).name() == typeid(var).name();
}

/**
 * @brief instanceOfDouble
 * @tparam T 
 * @param var 
 * @return bool
*/
template<typename T>
bool instanceOfDouble(T var) {
	return typeid(double).name() == typeid(var).name();
}

/**
 * @brief instanceOfLongDouble
 * @tparam T 
 * @param var 
 * @return bool
*/
template<typename T>
bool instanceOfLongDouble(T var) {
	return typeid(long double).name() == typeid(T).name();
}

/**
 * @brief instanceOfLongInt
 * @tparam T 
 * @param var 
 * @return bool
*/
template<typename T>
bool instanceOfLongInt(T var) {
	return typeid(long int).name() == typeid(var).name();
}

/**
 * @brief instanceOf
 * @tparam T 
 * @param var_1 
 * @param var_2 
 * @return bool
*/
template<typename T>
bool instanceOf(T var_1, T var_2) {
	return true;
}

/**
 * @brief instanceOf
 * @tparam T 
 * @tparam R 
 * @param var_1 
 * @param var_2 
 * @return bool
*/
template<typename T, typename R>
bool instanceOf(T var_1, R var_2) {
	return false;
}