/***********************************************************************
 * Module:  Input.cpp
 * Author:  USUARIO
 * Modified: domingo, 31 de mayo de 2020 11:33:33
 * Purpose: Implementation of Input
 ***********************************************************************/

#include "Input.h"
#include "Verify_number.cpp"

#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#pragma once

using namespace std;

/**
 * @brief input
 * @param input_phrase 
 * @return string
*/
string Input::input(std::string input_phrase)
{
	string aux;
	do {
		cout << input_phrase;
		getline(cin, aux);
		try {
			if (aux.length() == 0) {
				throw 1;
			}
			break;
		}
		catch (int e) {
			cout << "ERROR: Cadena vacia" << endl;
		}

	} while (1);

	return aux;
}

/**
 * @brief input_number
 * @param input_phrase 
 * @return string
*/
string Input::input_number(std::string input_phrase)
{
	string aux;
	do {
		cout << input_phrase;
		getline(cin, aux);
		try {
			if (aux.length() == 0) {
				throw 1;
			}
			if (!is_float_number(aux)) {
				throw aux;
			}
			break;
		}
		catch (int e) {
			cout << "ERROR: Cadena vacia" << endl;
		}
		catch (string e) {
			cout << "ERROR: " << aux << "-- No es un numero" << endl;
		}

	} while (1);

	return aux;
}

/**
 * @brief input_int_number
 * @param input_phrase 
 * @return string
*/
string Input::input_int_number(std::string input_phrase)
{
	string aux;
	do {
		cout << input_phrase;
		getline(cin, aux);
		try {
			if (aux.length() == 0) {
				throw 1;
			}
			if (!is_int_number(aux)) {
				throw aux;
			}
			break;
		}
		catch (int e) {
			cout << "ERROR: Cadena vacia" << endl;
		}
		catch (string e) {
			cout << "ERROR: " << aux << "-- No es un numero" << endl;
		}

	} while (1);

	return aux;
}

/**
 * @brief input_only_numbers
 * @param input_phrase 
 * @return string
*/
string Input::input_only_numbers(std::string input_phrase)
{
	string aux;
	int letter;
	cout << input_phrase;
	while (((letter = _getch()) != 13) || (aux.length() == 0)) {
		if (48 <= letter && letter <= 57 || letter == 46) {
			aux += (char)letter;
			printf("%c", letter);
		}
		else if (letter == 8) {
			system("cls");
			aux = _delete(aux);
			cout << input_phrase;
			cout << aux;
		}
	}

	printf("\n");
	return aux;
}

/**
 * @brief input_only_int
 * @param input_phrase 
 * @return string
*/
string Input::input_only_int(std::string input_phrase)
{
	string aux;
	int letter;
	cout << input_phrase;
	while (((letter = _getch()) != 13) || (aux.length() == 0)) {
		if (48 <= letter && letter <= 57) {
			aux += (char)letter;
			printf("%c", letter);
		}
		else if (letter == 8) {
			system("cls");
			aux = _delete(aux);
			cout << input_phrase;
			cout << aux;
		}
	}

	printf("\n");
	return aux;
}

/**
 * @brief input_only_letters
 * @param input_phrase 
 * @return string
*/
string Input::input_only_letters(std::string input_phrase)
{
	string aux;
	int letter;
	cout << input_phrase;
	while (((letter = _getch()) != 13) || (aux.length() == 0)) {
		if ('A' <= letter && letter <= 'Z' || 'a' <= letter && letter <= 'z') {
			aux += (char)letter;
			printf("%c", letter);
		}
		else if (letter == 8) {
			system("cls");
			aux = _delete(aux);
			cout << input_phrase;
			cout << aux;
		}
	}

	printf("\n");
	return aux;
}

/**
 * @brief input_only_letters
 * @param input_phrase 
 * @param _case 
 * @return string
*/
string Input::input_only_letters(std::string input_phrase, Case _case)
{
	string aux;
	int letter;
	cout << input_phrase;
	while (((letter = _getch()) != 13) || (aux.length() == 0)) {
		switch (_case) {
		case UPPER_CASE:
			if ('A' <= letter && letter <= 'Z') {
				aux += (char)letter;
				printf("%c", letter);
			}
			break;
		case LOWER_CASE:
			if ('a' <= letter && letter <= 'z') {
				aux += (char)letter;
				printf("%c", letter);
			}
			break;
		}

		if (letter == 8) {
			system("cls");
			aux = _delete(aux);
			cout << input_phrase;
			cout << aux;
		}
	}

	printf("\n");
	return aux;
}

/**
 * @brief _delete
 * @param string_for_delete 
 * @return string
*/
string Input::_delete(std::string string_for_delete) {
	string aux = "";
	for (int i = 0; i < string_for_delete.length() - 1 && string_for_delete != ""; i++) {
		aux += string_for_delete[i];
	}
	return aux;
}
