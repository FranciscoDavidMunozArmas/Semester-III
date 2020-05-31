/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* NOMBRE: Muñoz Armas Francisco David							  *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396                                                       *
******************************************************************/

#include <iostream>
#include "../Fraction/Fraction.cpp"

#pragma once
using namespace std;

class Operation {
public:
	Fraction calculate(Fraction frac_1, Fraction frac_2);
};

////////////////////////////////////////////////////////////////////////
// Name:       Operation::calculate(Fraction frac_1, Fraction frac_2)
// Purpose:    Implementation of Operation::calculate(Fraction frac_1, Fraction frac_2)
// Parameters:
// - frac_1
// - frac_2
// Return:     Fraction
////////////////////////////////////////////////////////////////////////
Fraction Operation::calculate(Fraction frac_1, Fraction frac_2) {
	Fraction aux;
	aux.set_numerator((frac_1.get_numerator()*frac_2.get_denominator()) + (frac_1.get_denominator()* frac_2.get_numerator()));
	aux.set_denominator(frac_1.get_denominator()*frac_2.get_denominator());

	return aux;
}
