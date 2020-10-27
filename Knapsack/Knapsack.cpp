/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Implementation of Knapsack
*/

#include "Knapsack.h"
#include "Knapsack_Item.cpp"
#include "Libraries/Array_dinamic.cpp"

/**
 * @brief Knapsack
 * @return
*/
Knapsack::Knapsack() {
	this->max_weight = 15;
	//this->_max_value = 20;
	_backpack = (Knapsack_Item*)malloc(1 * sizeof(Knapsack_Item));
}

/**
 * @brief Knapsack
 * @param max_weight
 * @return
*/
Knapsack::Knapsack(double max_weight) {
	this->max_weight = max_weight;
	_backpack = (Knapsack_Item*)malloc(1 * sizeof(Knapsack_Item));
}

/**
 * @brief Knapsack
 * @param max_weight
 * @return
*/
/*Knapsack::Knapsack(double max_weight, int _max_value) {
	this->max_weight = max_weight;
	this->_max_value = _max_value;
	_backpack = (Knapsack_Item*)malloc(1 * sizeof(Knapsack_Item));
}*/

/**
 * @brief _fill_pack
 * @param item_index
 * @param _weight
 * @return double
*/
double Knapsack::_fill_pack(int item_index, double _weight) {

	if (item_index < 1 || _weight <= 0) {
		cout << endl;
		return 0;
	}
	else {
		if ((_backpack + item_index)->_get_item_weight() > _weight) {
			return _fill_pack(item_index - 1, _weight);
		}
		else {
			cout << "Item - " << item_index << "\t$" << (_backpack + item_index)->_get_value() << "\t" << (_backpack + item_index)->_get_item_weight() << " kg" << endl;
			return (_backpack + item_index)->_get_item_weight() + _fill_pack(item_index - 1, _weight - (_backpack + item_index)->_get_item_weight());
		}
	}
}

/**
 * @brief _fill_pack
 * @param item_index
 * @param _weight
 * @return
*/
/*double Knapsack::_fill_pack(int item_index, double _weight, int* _combination) {
	if (item_index <= 0 || _weight <= 0) {
		return 0;
	}
	else if((_backpack + item_index)->_get_item_weight() > _weight) {
		cout << "Eliminar item - " << item_index << " " << (_backpack + item_index)->_get_item_weight() << " kg" << endl;
		return _fill_pack(item_index - 1, _weight, _combination);
	}
	else {
		return _get_max(_fill_pack(item_index - 1, _weight, _combination), (_backpack + item_index)->_get_item_weight() + _fill_pack(item_index - 1, _weight - (_backpack + item_index)->_get_item_weight(), _combination));
	}
}*/

/*double Knapsack::_fill_pack(int item_index, int _value, int* _combination) {
	if (item_index <= 0 || _value <= 0) {
		return 0;
	}
	else if ((_backpack + item_index)->_get_value() > _value) {
		cout << "Eliminar item - " << item_index << " $" << (_backpack + item_index)->_get_value() << endl;
		return _fill_pack(item_index - 1, _value, _combination);
	}
	else {
		return _get_max(_fill_pack(item_index - 1, _value, _combination), (_backpack + item_index)->_get_value() + _fill_pack(item_index - 1, _value - (_backpack + item_index)->_get_value(), _combination));
	}
}
/**
 * @brief _get_max
 * @tparam T
 * @param var_1
 * @param var_2
 * @return
*/
/*template<typename T>
double Knapsack::_get_max(T var_1, T var_2) {
	return (var_1 > var_2) ? var_1 : var_2;
}*/

/**
 * @brief _set_item
 * @param _new_item
*/
void Knapsack::_set_item(Knapsack_Item _new_item) {
	_backpack = _ad._resize(_backpack, _ad._dynamic_size(_backpack) + 1);
	*(_backpack + _ad._dynamic_size(_backpack) - 1) = _new_item;
}

/**
 * @brief _start_Knapsack
*/
void Knapsack::_start_Knapsack() {
	_sort_backpack();
	/*for (int i = 1; i < _ad._dynamic_size(_backpack); i++) {
		cout << (_backpack + i)->_get_value() << endl;
	}*/

	cout << endl;
	cout << endl << "Peso optimo: " << _fill_pack(_ad._dynamic_size(_backpack) - 1, this->max_weight) << " kg\t Mochila peso total: " << this->max_weight << " kg" << endl;
	//int combination = 0;
	//cout << endl;
	//cout << endl << "Peso Optimizado: " << _fill_pack(_ad._dynamic_size(_backpack) - 1, this->max_weight, &combination) << endl;
	//combination = 0;
	//cout << endl;
	//cout << endl << "Valor Optimizado: " << _fill_pack(_ad._dynamic_size(_backpack) - 1, this->_max_value, &combination) << endl;
	//free(_final_backpack);
	free(_backpack);
}

void Knapsack::_sort_backpack() {
	for (int i = 1; i < _ad._dynamic_size(_backpack) - 1; i++) {
		for (int j = i; j < _ad._dynamic_size(_backpack); j++) {
			if ((_backpack + i)->_get_value() > (_backpack + j)->_get_value()) {
				Knapsack_Item aux = *(_backpack + i);
				*(_backpack + i) = *(_backpack + j);
				*(_backpack + j) = aux;
			}
		}
	}
}

Knapsack::~Knapsack() {}
