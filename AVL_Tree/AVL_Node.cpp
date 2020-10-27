#include <iostream>
#include <sstream>

#include "AVL_Node.h"

using namespace std;

template<class T>
AVL_Node<T>::AVL_Node() {
	this->_left = NULL;
	this->_right = NULL;
	this->_parent = NULL;
	this->_balance_factor = 0;
}

template<class T>
AVL_Node<T>::AVL_Node(T _data, AVL_Node<T>* _left, AVL_Node<T>* _right, AVL_Node<T>* _parent) {
	this->_data = _data;
	this->_left = _left;
	this->_right = _right;
	this->_parent = _parent;
	this->_balance_factor = 0;
}

template<class T>
void AVL_Node<T>::set_data(T _data) {
	this->_data = _data;
}

template<class T>
void AVL_Node<T>::set_left_node(AVL_Node<T>* _left) {
	this->_left = _left;
}

template<class T>
void AVL_Node<T>::set_right_node(AVL_Node<T>* _right) {
	this->_right = _right;
}

template<class T>
void AVL_Node<T>::set_parent_node(AVL_Node* _parent) {
	this->_parent = _parent;
}

template<class T>
void AVL_Node<T>::set_balance_factor(int _balance_factor) {
	this->_balance_factor = _balance_factor;
}

template<class T>
void AVL_Node<T>::add_balance_factor(int _balance_factor) {
	this->_balance_factor += _balance_factor;
}

template<class T>
T AVL_Node<T>::get_data() {
	return 	this->_data;
}

template<class T>
AVL_Node<T>* AVL_Node<T>::get_right_node() {
	return this->_right;
}

template<class T>
AVL_Node<T>* AVL_Node<T>::get_left_node() {
	return this->_left;
}

template<class T>
AVL_Node<T>* AVL_Node<T>::get_parent_node() {
	return this->_parent;
}

template<class T>
int AVL_Node<T>::get_balance_factor() {
	return this->_balance_factor;
}

template<class T>
string AVL_Node<T>::to_string() {
	ostringstream oss;
	oss << this->_data;
	return oss.str();
}

template<class T>
AVL_Node<T>::~AVL_Node() {}
