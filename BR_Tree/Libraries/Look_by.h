/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of Look_by
*/

#if !defined(__Look_by)
#define __Look_by

#include "List_Circle_Double.h"

#include <iostream>

using namespace std;

class Look_by{
public:
	template<typename R, class T>
	int look_by_key(R _key, List_Circle_Double<T>* _list);
	//int look_by_key(char* _key, char**_key_array);
	int look_by_key(char* _key, char** _key_array, int _index);
};

#endif
