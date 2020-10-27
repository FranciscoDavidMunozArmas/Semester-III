/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Viernes, 26 de Junio de 2020
 * @function Declaration of Order_1_
*/

#if !defined(__Order)
#define __Order

#include <iostream>

using namespace std;

class Order
{
public:
private:
protected:
	virtual void _run(int _index) = 0;
	void _delay();
};

#endif
