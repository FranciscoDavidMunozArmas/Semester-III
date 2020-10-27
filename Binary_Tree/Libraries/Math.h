/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of Math
*/

#if !defined(__ObjectOrientedModel_1_Math_h)
#define __ObjectOrientedModel_1_Math_h

class Math
{
public:
	template<typename T>
	double pow(T base, int index);
	int factorial(int base);
	template<typename T>
	T _abs(T _num);
protected:
private:

};

#endif