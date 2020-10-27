/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Viernes, 26 de Junio de 2020
 * @function Implementation of Order
*/
#include "Order.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#pragma once

using namespace std;

/**
 * @brief _delay
*/
void Order::_delay() {
	int max = 999999;
	int* _array = (int*)malloc(max*sizeof(int));
	for (int i = 0; i < max; i++) {
		*(_array + i) = i;
	}
}
