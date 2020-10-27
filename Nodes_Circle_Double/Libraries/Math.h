/***********************************************************************
 * Module:  Math.h
 * Author:  USUARIO
 * Modified: martes, 2 de junio de 2020 15:47:09
 * Purpose: Declaration of the class Math
 ***********************************************************************/

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