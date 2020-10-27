/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of RUC_verificator
*/

#if !defined(__RUC_verificator_h)
#define __RUC_verificator_h

#include <iostream>
#include "ID_verificator.h"

using namespace std;

class RUC_verificator : public ID_verificator {
public:
	bool RUC_verify(char* RUC);
private:
	bool check_for_6(char* RUC, int coef_1, int coef_2, int coef_3, int coef_4, int coef_5, int coef_6, int coef_7, int coef_8);
	bool check_for_9(char* RUC, int coef_1, int coef_2, int coef_3, int coef_4, int coef_5, int coef_6, int coef_7, int coef_8, int coef_9);
	bool last_digits(char* digits);
	int get_module(int num, int den);
};

#endif
