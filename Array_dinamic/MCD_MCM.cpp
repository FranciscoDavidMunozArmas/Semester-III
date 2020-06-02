/***********************************************************************
 * Module:  MCD_MCM.cpp
 * Author:  USUARIO
 * Modified: lunes, 1 de junio de 2020 15:32:38
 * Purpose: Implementation of the MCD_MCM
 ***********************************************************************/

#include "MCD_MCM.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       add(T** matrix, int _size)
// Purpose:    Implementation of add(T** matrix, int _size)
// Parameters:
// - _array
// - _size
// Return:     int
////////////////////////////////////////////////////////////////////////

template<typename T>
int commun_minum(T* _array, int _size)
{
	bool flag = true;
	int max = 0, counter;
	int multiple = 0;
    int max_number = *(_array + _size - 1);
	while (flag) {
		counter = 0;
		max++;
		multiple = max_number * max;
		for (int i = 0; i < _size; i++) {
			if (! (max% *(_array + i))) {
				counter++;
			}
		}
		if (counter == _size) {
			flag = false;
		}
	}

	return max;
}

////////////////////////////////////////////////////////////////////////
// Name:       commun_maxinum(T* _array, int _size)
// Purpose:    Implementation of commun_maxinum(T* _array, int _size)
// Parameters:
// - _array
// - _size
// Return:     int
////////////////////////////////////////////////////////////////////////

template<typename T>
int commun_maxinum(T* _array, int _size)
{
	int minum, number, aux;
	for (int i = 0; i < _size; i++) {
		number = *(_array + i);
		if (i == 0) {
			minum = number;
		}
		do {
			aux = minum % number;
			minum = number;
			number = aux;
		} while (aux != 0);
	}

	return minum;
}

