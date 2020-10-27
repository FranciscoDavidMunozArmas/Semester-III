/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Viernes, 26 de Junio de 2020
 * @function Implementation of Order_N_2
*/
#include "O(n-2).h"
#include "Order.cpp"

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/**
 * @brief _run
 * @param _index 
*/
void Order_N_2::_run(int _index) {

	clock_t _start = clock() / (CLOCKS_PER_SEC / 1000);

	for (int i = 0; i < _index; i++) {
		for (int j = 0; j < _index; j++) {
			_delay();
		}
	}

	_delay();

	clock_t _end = clock() / (CLOCKS_PER_SEC / 1000);

	cout << _index << endl;
	cout << (_end - _start) << " miliseconds" << endl << endl;
}
