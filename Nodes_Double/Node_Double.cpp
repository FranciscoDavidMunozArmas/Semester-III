#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "Node_Double.h"

#pragma once

using namespace std;

template<class T>
Node_Double<T>::Node_Double() {
	this->_next = NULL;
	this->_back = NULL;
}

template<class T>
Node_Double<T>::Node_Double(T _data, Node_Double* _next, Node_Double* _back) {
	this->data = _data;
	this->_next = _next;
	this->_back = _back;
}

template<class T>
void Node_Double<T>::_set_data(T _data) {
	this->data = _data;
}

template<class T>
void Node_Double<T>::_set_next_node(Node_Double* _node) {
	this->_next = _node;
}

template<class T>
void Node_Double<T>::_set_back_node(Node_Double* _node) {
	this->_back = _node;
}

template<class T>
T Node_Double<T>::_get_data() {
	return this->data;
}

template<class T>
Node_Double<T>* Node_Double<T>::_get_next_node() {
	return this->_next;
}

template<class T>
Node_Double<T>* Node_Double<T>::_get_back_node() {
	return this->_back;
}

template<class T>
string Node_Double<T>::to_string() {
	ostringstream oss;
	oss << " <- "<< this->data << " -> ";
	
	return oss.str();
}

template<class T>
Node_Double<T>::~Node_Double() {}
