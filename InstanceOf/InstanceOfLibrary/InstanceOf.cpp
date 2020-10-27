/***********************************************************************
 * Module:  InstanceOf.cpp
 * Author:  USUARIO
 * Modified: miércoles, 27 de mayo de 2020 15:31:15
 * Purpose: Implementation of the class InstanceOf
 ***********************************************************************/

#include <iostream>
#include <typeinfo>
#include "InstanceOf.h"

using namespace std;

template<typename T>
bool intanceOfString(T var) {
	return typeid(string).name() == typeid(var).name();
}

template<typename T>
bool instanceOfInt(T var) {
	return typeid(int).name() == typeid(var).name();
}

template<typename T>
bool instanceOfFloat(T var) {
	return typeid(float).name() == typeid(var).name();
}

template<typename T>
bool instanceOfDouble(T var) {
	return typeid(double).name() == typeid(var).name();
}

template<typename T>
bool instanceOfLongDouble(T var) {
	return typeid(long double).name() == typeid(T).name();
}

template<typename T>
bool instanceOfLongInt(T var) {
	return typeid(long int).name() == typeid(var).name();
}

template<typename T>
bool instanceOf(T var_1, T var_2) {
	return true;
}

template<typename T, typename R>
bool instanceOf(T var_1, R var_2) {
	return false;
}
