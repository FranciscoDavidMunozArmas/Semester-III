/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Implementation of Validar
*/

#include <iostream>

#include "Validar.h"

using namespace std;

/**
 * @brief Validar
 * @return 
*/
Validar::Validar() {}

/**
 * @brief validar
 * @param entrada 
 * @param tipo 
 * @return bool
*/
bool Validar::validar(string entrada, int tipo) {
	int contador = 0;
	try {
		for (int i = 0; i < entrada.length(); i++) {
			if (isalpha(entrada[i])) {
				throw 1;
			}
			if (!isdigit(entrada[i]) && tipo == 1) {
				throw 1;
			}
			if (entrada[i] == '.') {
				contador++;
			}
			if ((isdigit(entrada[i]) == 0 && entrada[i] != '.') || (contador > 1)) {
				throw 1;
			}
		}
	}
	catch (int e) {
		return true;
	}
	return false;
}

/**
 * @brief ~Validar
 * @return 
*/
Validar::~Validar() {}
