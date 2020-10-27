/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Viernes, 26 de Junio de 2020
 * @function Declaration of Order_n_
*/
#if !defined(__Order_N_)
#define __Order_N_

#include <iostream>

#include "Order.h"

using namespace std;

class Order_n_ : public Order
{
public:
	void _run(int _index);
private:
protected:
};

#endif
