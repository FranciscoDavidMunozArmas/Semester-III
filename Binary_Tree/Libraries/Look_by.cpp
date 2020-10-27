/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of Look_by
*/

#include "Look_by.h"
#include <string>

#include "Array_dinamic.cpp"

#include "List_Circle_Double.cpp"
#include "Node_Double.cpp"

#pragma once

using namespace std;

/**
 * @brief look_by_key
 * @param _key
 * @param _key_array
 * @param _index
 * @return int
*/
int Look_by::look_by_key(char* _key, char** _key_array, int _index) {
	if (_index <= -1) {
		return -1;
	} else  if (strcmp(_key, *(_key_array + _index)) == 0) {
		return _index;
	}
	else {
		look_by_key(_key, _key_array, _index - 1);
	}
}

/**
 * @brief look_by_key
 * @tparam R 
 * @tparam T 
 * @param _key 
 * @param _list 
 * @return 
*/
template<typename R, class T>
int Look_by::look_by_key(R _key, List_Circle_Double<T>* _list) {
	int _index = 0;
	Node_Double<T>* _node = _list->_get_node();
	Node_Double<T>* _last_node = _list->_get_end_node();
	while ((_node != _last_node)&&!(_node->_get_data() == _key)) {
		_node = _node->_get_next_node();
		_index++;
	}
	if (_last_node == _node) {
		if (!(_last_node->_get_data() == _key)) {
			_index = -1;
		}
	}

	return _index;
}
