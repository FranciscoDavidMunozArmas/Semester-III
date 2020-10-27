/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of Node_Double
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "Node_Double.h"

#pragma once

using namespace std;

/**
 * @brief Node_Double
 * @tparam T 
 * @return 
*/
template<class T>
Node_Double<T>::Node_Double() {
	this->_next = NULL;
	this->_back = NULL;
}

/**
 * @brief Node_Double
 * @tparam T 
 * @param _data 
 * @param _next 
 * @param _back 
 * @return 
*/
template<class T>
Node_Double<T>::Node_Double(T _data, Node_Double* _next, Node_Double* _back) {
	this->data = _data;
	this->_next = _next;
	this->_back = _back;
}

/**
 * @brief _set_data
 * @tparam T 
 * @param _data 
*/
template<class T>
void Node_Double<T>::_set_data(T _data) {
	this->data = _data;
}

/**
 * @brief _set_next_node
 * @tparam T 
 * @param _node 
*/
template<class T>
void Node_Double<T>::_set_next_node(Node_Double* _node) {
	this->_next = _node;
}

/**
 * @brief _set_back_node
 * @tparam T 
 * @param _node 
*/
template<class T>
void Node_Double<T>::_set_back_node(Node_Double* _node) {
	this->_back = _node;
}

/**
 * @brief _get_data
 * @tparam T 
 * @return T
*/
template<class T>
T Node_Double<T>::_get_data() {
	return this->data;
}

/**
 * @brief _get_next_node
 * @tparam T 
 * @return 
*/
template<class T>
Node_Double<T>* Node_Double<T>::_get_next_node() {
	return this->_next;
}

/**
 * @brief _get_back_node
 * @tparam T 
 * @return Node_Double<T>*
*/
template<class T>
Node_Double<T>* Node_Double<T>::_get_back_node() {
	return this->_back;
}

/**
 * @brief to_string
 * @tparam T 
 * @return string
*/
template<class T>
string Node_Double<T>::to_string() {
	ostringstream oss;
	oss << this->data;
	
	return oss.str();
}

/**
 * @brief ~Node_Double
 * @tparam T 
 * @return 
*/
template<class T>
Node_Double<T>::~Node_Double() {}
