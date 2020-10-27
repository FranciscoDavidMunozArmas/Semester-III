#include <iostream>
#include <sstream>

#include "BR_Node.h"

using namespace std;

template<class T>
BR_Node<T>::BR_Node() {
	this->_left = NULL;
	this->_right = NULL;
	this->_parent = NULL;
	this->_color = BR_COLOR::BLACK;
}

template<class T>
BR_Node<T>::BR_Node(T _data, BR_Node* _left, BR_Node* _right, BR_Node* _parent, BR_COLOR _color) {
	this->_data = _data;
	this->_left = _left;
	this->_right = _right;
	this->_parent = _parent;
	this->_color = _color;
}

template<class T>
void BR_Node<T>::set_data(T _data) {
	this->_data = _data;
}

template<class T>
void BR_Node<T>::set_left_node(BR_Node<T>* _left) {
	this->_left = _left;
}

template<class T>
void BR_Node<T>::set_right_node(BR_Node<T>* _right) {
	this->_right = _right;
}

template<class T>
void BR_Node<T>::set_parent_node(BR_Node* _parent) {
	this->_parent = _parent;
}

template<class T>
void BR_Node<T>::set_color(BR_COLOR _color) {
	this->_color = _color;
}

template<class T>
T BR_Node<T>::get_data() {
	return 	this->_data;
}

template<class T>
BR_Node<T>* BR_Node<T>::get_right_node() {
	return this->_right;
}

template<class T>
BR_Node<T>* BR_Node<T>::get_left_node() {
	return this->_left;
}

template<class T>
BR_Node<T>* BR_Node<T>::get_parent_node() {
	return this->_parent;
}

template<class T>
BR_COLOR BR_Node<T>::get_color() {
	return this->_color;
}

template<class T>
string BR_Node<T>::to_string() {
	ostringstream oss;
	oss << this->_data;
	return oss.str();
}

template<class T>
BR_Node<T>::~BR_Node() {}
