/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Viernes, 26 de Junio de 2020
 * @function Declaration of Order_1_
*/

#if !defined(__Order_1_)
#define __Order_1_

#include <iostream>

#include "Order.h"

using namespace std;

class Order_1_ : public Order
{
public:
	void _run(int _index);
private:
protected:
};

#endif
