/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Implementation of Knapsack_Item
*/

#include "Knapsack_Item.h"

#pragma once

/**
 * @brief Knapsack_Item
 * @param _item_weight 
 * @param _value 
 * @return 
*/
Knapsack_Item::Knapsack_Item(double _item_weight, int _value) {
	this->_item_weight = _item_weight;
	if (_value < 1) {
		_value = 1;
	}
	this->_value = _value;
}

/**
 * @brief _get_item_weight
 * @return double
*/
double Knapsack_Item::_get_item_weight() {
	return this->_item_weight;
}

/**
 * @brief _get_value
 * @return int
*/
int Knapsack_Item::_get_value() {
	return this->_value;
}

/**
 * @brief ~Knapsack_Item
 * @return 
*/
Knapsack_Item::~Knapsack_Item() {}
