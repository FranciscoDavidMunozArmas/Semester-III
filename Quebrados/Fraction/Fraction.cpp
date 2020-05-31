/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* NOMBRE: Muñoz Armas Francisco David							  *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396                                                       *
******************************************************************/

#include <iostream>
#include<sstream>

#pragma once
using namespace std;

class Fraction {
public:
	Fraction();
	float get_numerator(void);
	float get_denominator(void);
	void set_numerator(float numerator);
	void set_denominator(float denominator);
	string to_string();
private:
	float numerator;
	float denominator;
};

Fraction::Fraction() {
	this->numerator = 0;
	this->denominator = 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraction::get_numerator(void)
// Purpose:    Implementation of Fraction::get_numerator(void)
// Return:     float
////////////////////////////////////////////////////////////////////////
float Fraction::get_numerator(void) {
	return numerator;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraction::get_denominator(void)
// Purpose:    Implementation of Fraction::get_denominator(void)
// Return:     float
////////////////////////////////////////////////////////////////////////
float Fraction::get_denominator(void) {
	return denominator;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraction::set_numerator(float numerator)
// Purpose:    Implementation of Fraction::set_numerator(float numerator)
// Parameters:
// - numerator
// Return:     void
////////////////////////////////////////////////////////////////////////
void Fraction::set_numerator(float numerator) {
	this->numerator = numerator;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraction::set_denominator(float denominator)
// Purpose:    Implementation of Fraction::set_denominator(float denominator)
// Parameters:
// - denominator
// Return:     void
////////////////////////////////////////////////////////////////////////
void Fraction::set_denominator(float denominator) {
	this->denominator = denominator;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraction::to_string()
// Purpose:    Implementation of Fraction::to_string()
// Return:     string
////////////////////////////////////////////////////////////////////////
string Fraction::to_string() {
	stringstream s;
	s << numerator << "/" << denominator;
	return s.str();
}