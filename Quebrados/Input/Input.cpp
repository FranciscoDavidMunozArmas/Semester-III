/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* NOMBRE: Muñoz Armas Francisco David							  *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396                                                       *
******************************************************************/

#include <iostream>
#include <string>

#pragma once
using namespace std;

class Input {
public:
	Input();
	string input_number(string input_phrase);
	float string_to_float(string string_number);
private:
	bool verify_number(string verify_string);
};

////////////////////////////////////////////////////////////////////////
// Name:       Input::Input()
// Purpose:    Implementation of Input::Input()
// Return:     
////////////////////////////////////////////////////////////////////////
Input::Input() {}

////////////////////////////////////////////////////////////////////////
// Name:       Input::input_number(string input_phrase)
// Purpose:    Implementation of Input::input_number(string input_phrase)
// Parameters:
// - input_phrase
// Return:     string
////////////////////////////////////////////////////////////////////////
string Input::input_number(string input_phrase) {
	string aux;
	do{
		cout << input_phrase;
		getline(cin, aux);
		try {
			if (!verify_number(aux)) {
				throw 1;
			}
			break;
		}
		catch (int e) {
			cout << "Error... No es un numero" << endl;
		}
	} while (true);
	return aux;
}

////////////////////////////////////////////////////////////////////////
// Name:       Input::verify_number(string verify_string)
// Purpose:    Implementation of Input::verify_number(string verify_string)
// Parameters:
// - verify_string
// Return:     bool
////////////////////////////////////////////////////////////////////////
bool Input::verify_number(string verify_string) {
	for (char aux: verify_string) {
		if (!isdigit(aux) && aux != '.') {
			return false;
		}
	}
	return true;
}

////////////////////////////////////////////////////////////////////////
// Name:       Input::string_to_float(string string_number)
// Purpose:    Implementation of Input::string_to_float(string string_number)
// Parameters:
// - newNum1
// Return:     float
////////////////////////////////////////////////////////////////////////
float Input::string_to_float(string string_number) {
	return stof(string_number);
}