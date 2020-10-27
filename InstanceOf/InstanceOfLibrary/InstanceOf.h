/***********************************************************************
 * Module:  InstanceOf.h
 * Author:  USUARIO
 * Modified: miércoles, 27 de mayo de 2020 15:31:15
 * Purpose: Declaration of the class InstanceOf
 ***********************************************************************/

#if !defined(__InstanceOf_h)
#define __InstanceOf_h
template<class T>
	bool intanceOfString(T var);
template<class T>
	bool instanceOfInt(T var);
template<class T>
	bool instanceOfFloat(T var);
template<class T>
	bool instanceOfDouble(T var);
template<class T>
	bool instanceOfLongDouble(T var);
template<class T>
	bool instanceOfLongInt(T var);
template<class T, class R>
	bool instanceOf(T var_1, T var_2);
template<class T, class R>
	bool instanceOf(T var_1, R var_2);

#endif
