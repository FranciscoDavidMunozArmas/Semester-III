/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Implementation of Ingreso
*/

#include <iostream>

#include "Ingreso.h"
#include "Validar.cpp"

#pragma once

using namespace std;

/**
 * @brief Ingreso
 * @return 
*/
Ingreso::Ingreso() {}

/**
 * @brief leer
 * @param mensage 
 * @param tipo 
 * @return string
*/
string Ingreso::leer(string mensage, int tipo) {
	Validar validacion;
	string entrada;
	cout << mensage << endl;
	cin >> entrada;
	while (validacion.validar(entrada, tipo)) {
		cout << "Valor no valido reingrese" << endl;
		cin >> entrada;
	}
	return entrada;

}

/**
 * @brief ~Ingreso
 * @return 
*/
Ingreso::~Ingreso() {}
