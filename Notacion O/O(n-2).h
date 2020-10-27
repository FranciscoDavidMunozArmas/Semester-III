/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Viernes, 26 de Junio de 2020
 * @function Declaration of Order_N_2
*/

#if !defined(__Order_N_2_)
#define __Order_N_2_

#include <iostream>

#include "Order.h"

using namespace std;

class Order_N_2 : public Order
{
public:
	void _run(int _index);
private:
protected:
};

#endif
