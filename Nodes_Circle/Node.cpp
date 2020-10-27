#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "Node.h"

#pragma once

using namespace std;

template<class T>
Node<T>::Node() {
	this->_next = NULL;
}

template<class T>
Node<T>::Node(T _data, Node* _next) {
	this->data = _data;
	this->_next = _next;
}

template<class T>
void Node<T>::_set_data(T _data) {
	this->data = _data;
}

template<class T>
void Node<T>::_set_node(Node* _node) {
	this->_next = _node;
}

template<class T>
T Node<T>::_get_data() {
	return this->data;
}

template<class T>
Node<T>* Node<T>::_get_node() {
	return this->_next;
}

template<class T>
string Node<T>::to_string() {
	ostringstream oss;
	oss << this->data << " -> ";
	
	return oss.str();
}

template<class T>
Node<T>::~Node() {}
