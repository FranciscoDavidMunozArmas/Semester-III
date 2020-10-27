/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Implementation of Input_Byte
*/

#include "Input_Byte.h"

#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ENTER 13
#define BACK_SPACE 8

using namespace std;

/**
 * @brief Input_Byte
 * @return 
*/
Input_Byte::Input_Byte() {}

/**
 * @brief _input
 * @param _msg 
 * @return string
*/
string Input_Byte::_input(char* _msg) {
	string _aux = "";
	int letter = 0;
	cout << _msg;
	while ((letter != ENTER)||(_aux.length() == 0)) {
		letter = _getch();
		if (letter == BACK_SPACE) {
			system("cls");
			_aux = _delete(_aux);
			cout << _msg << _aux;
		}
		else{
			if ('A' <= letter && letter <= 'Z' || 'a' <= letter && letter <= 'z') {
				letter = _upper_lower((char)letter);
				_aux += (char)letter;
			}
			else {
				_aux += (char)letter;
			}
			cout << (char)(letter);
		}
	}

	return _aux;
}

/**
 * @brief _upper_lower
 * @param _letter 
 * @return char
*/
char Input_Byte::_upper_lower(char _letter) {
	return (char)(_letter ^ 32);
}

/**
 * @brief _delete
 * @param str_delete 
 * @return string
*/
string Input_Byte::_delete(string str_delete) {
	string aux = "";
	for (int i = 0; i < str_delete.length() - 1 && str_delete != ""; i++) {
		aux += str_delete[i];
	}
	return aux;
}

/**
 * @brief ~Input_Byte
 * @return 
*/
Input_Byte::~Input_Byte() {}
