#include <sstream>
#include <string>

#include "Stack.h"
#include "Node.cpp"

#pragma once

/**
 * @brief Stack
 * @tparam T
 * @return
*/
template<class T>
Stack<T>::Stack() {
	this->_node = NULL;
}

/**
 * @brief _push
 * @tparam T
 * @param _data
*/
template<class T>
void Stack<T>::_push(T _data) {
	if (_is_empty()) {
		this->_node = new Node<T>(_data, NULL);
	}
	else {
		Node<T>* _aux = new Node<T>(_data, this->_node);
		this->_node = _aux;
	}
}

/**
 * @brief _pop
 * @tparam T
 * @return T
*/
template<class T>
T Stack<T>::_pop() {
	if (_is_empty()) {
		cout << "Pila vacia" << endl;
	}
	else {
		T _aux = this->_node->_get_data();
		this->_node = this->_node->_get_node();
		return _aux;
	}
}

/**
 * @brief _clear_all
 * @tparam T
*/
template<class T>
void Stack<T>::_clear_all() {
	Node<T>* _aux;
	while (this->_node != NULL) {
		_aux = this->_node;
		this->_node = this->_node->_get_node();
		delete _aux;
	}
}

/**
 * @brief _is_empty
 * @tparam T
 * @return bool
*/
template<class T>
bool Stack<T>::_is_empty() {
	return (this->_node == NULL) ? true : false;
}

/**
 * @brief _top
 * @tparam T
 * @return
*/
template<class T>
T Stack<T>::_top() {
	if (_is_empty()) {
		cout << "Pila vacia" << endl;
	}
	else {
		return this->_node->_get_data();
	}
}

/**
 * @brief to_string
 * @tparam T
 * @return string
*/
template<class T>
string Stack<T>::to_string() {
	ostringstream oss;
	Node<T>* _aux = this->_node;
	oss << "Cima -> ";
	while (_aux != NULL) {
		oss << _aux->to_string();
		_aux = _aux->_get_node();
	}
	oss << "NULL";
	return oss.str();
}

/**
 * @brief ~Stack()
 * @tparam T
 * @return
*/
template<class T>
Stack<T>::~Stack() {
	this->_clear_all();
}
