/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* NOMBRE: Muñoz Armas Francisco David							  *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396                                                       *
******************************************************************/

#include <iostream>
#include <stdlib.h>
#include "../Fraction/Fraction.cpp"
#include "../Input/Input.cpp"
#include "../Operation/Operation.cpp"

int main(){
    Input input;
    Fraction frac_1, frac_2, frac_result;
    Operation operation;
    for (int i = 0; i < 2; i++) {
        cout << "Fraccion " << i + 1 << endl;
        string numerator = input.input_number("Introduce el numerador: ");
        string denominator = input.input_number("Introduce el denominator: ");
        if (i == 0) {
            frac_1.set_numerator(input.string_to_float(numerator));
            frac_1.set_denominator(input.string_to_float(denominator));
        }
        else if (i == 1) {
            frac_2.set_numerator(input.string_to_float(numerator));
            frac_2.set_denominator(input.string_to_float(denominator));
        }
    }

    frac_result = operation.calculate(frac_1, frac_2);
    system("cls");
    cout << "Fraccion 1: " << frac_1.to_string() << endl;
    cout << "Fraccion 2: " << frac_2.to_string() << endl;
    cout << " ((a*d)+(b*c))/(b*d) " << endl;
    cout << "Respuesta: " << frac_result.to_string() << endl;
}