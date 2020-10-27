/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date viernes, 21 de agosto de 2020 10:07:14
 * @function Implementation Binary_Tree
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

#include "Binary_Tree.h"
#include "Tree_Node.cpp"

#pragma once

using namespace std;

/**
 * @brief _add
 * @tparam T
 * @param _data
*/
template<typename T>
void Binary_Tree<T>::_add(T _data) {
	if (this->_is_empty()) {
		Tree_Node<T>* _data_node = new Tree_Node<T>(_data, NULL, NULL);
		this->_root = _data_node;
	}
	else {
		Tree_Node<T>* _aux = this->_root;
		_add(this->_root, _data);
	}
}

/**
 * @brief _add
 * @tparam T
 * @param _node
 * @param _data
*/
template<typename T>
void Binary_Tree<T>::_add(Tree_Node<T>* _node, T _data) {
	if (_data < _node->get_data()) {
		if (_node->get_left_node() == NULL) {
			Tree_Node<T>* _data_node = new Tree_Node<T>(_data, NULL, NULL);
			_node->set_left_node(_data_node);
		}
		else {
			_add(_node->get_left_node(), _data);
		}
	}
	else {
		if (_node->get_right_node() == NULL) {
			Tree_Node<T>* _data_node = new Tree_Node<T>(_data, NULL, NULL);
			_node->set_right_node(_data_node);
		}
		else {
			_add(_node->get_right_node(), _data);
		}
	}
}

/**
 * @brief _look
 * @tparam T
 * @param _data
 * @return bool
*/
template<typename T>
template<typename R>
T* Binary_Tree<T>::_look(R _data) {
	if (this->_is_empty()) {
		cout << "Nodo Vacio" << endl;
		return NULL;
	}
	else {
		return _look(this->_root, _data);
	}
}

/**
 * @brief _look
 * @tparam T
 * @param _node
 * @param _data
 * @return bool
*/
template<typename T>
template<typename R>
T* Binary_Tree<T>::_look(Tree_Node<T>* _node, R _data) {
	if (_node == NULL) {
		return NULL;
	}
	else if (_node->get_data() == _data) {
		return (T*)_node->get_data();
	}
	else {
		if (_data < _node->get_data()) {
			return _look(_node->get_left_node(), _data);
		}
		else {
			return _look(_node->get_right_node(), _data);
		}
	}
}

/**
 * @brief _delete
 * @tparam T
 * @param _data
*/
template<typename T>
template<typename R>
void Binary_Tree<T>::_delete(R _data) {
	if (this->_is_empty()) {
		cout << "Nodo Vacio" << endl;
	}
	else {
		_delete(this->_root, this->_root, _data);
	}
}

/**
 * @brief _delete
 * @tparam T
 * @param _node
 * @param _parent
 * @param _data
*/
template<typename T>
template<typename R>
void Binary_Tree<T>::_delete(Tree_Node<T>* _node, Tree_Node<T>* _parent, R _data) {
	if (_node == NULL) {
		cout << "No existe" << endl;
		return;
	}
	else {
		if (_data < _node->get_data()) {
			_delete(_node->get_left_node(), _node, _data);
		}
		else if (_node->get_data() < _data) {
			_delete(_node->get_right_node(), _node, _data);
		}
		else if (_node->get_data() == _data) {
			_delete_node(_node, _parent);
		}
	}
}

/**
 * @brief _delete_node
 * @tparam T
 * @param _node
 * @param _parent
*/
template<typename T>
void Binary_Tree<T>::_delete_node(Tree_Node<T>* _node, Tree_Node<T>* _parent) {
	if (_node->get_left_node() != NULL && _node->get_right_node() != NULL) {
		Tree_Node<T>* _aux = _node->get_left_node();
		Tree_Node<T>* _aux_1 = _aux;
		Tree_Node<T>* _aux_2 = _aux_1;
		while (_aux != NULL) {
			_aux_2 = _aux_1;
			_aux_1 = _aux;
			_aux = _aux->get_right_node();
        }
		_node->set_data(_aux_1->get_data());
		if (_aux_1 == _aux_2) {
			_delete_node(_aux_1, _node);
		}
		else {
			_delete_node(_aux_1, _aux_2);
		}
		return;
	}
	else if (_node->get_left_node() != NULL && _node->get_right_node() == NULL) {
		Tree_Node<T>* _aux = _node->get_left_node();
		_node->set_data(_aux->get_data());
		_node->set_left_node(_aux->get_left_node());
		_node->set_right_node(_aux->get_right_node());
		delete _aux;
		return;
	}
	else if (_node->get_left_node() == NULL && _node->get_right_node() != NULL) {
		Tree_Node<T>* _aux = _node->get_right_node();
		_node->set_data(_aux->get_data());
		_node->set_left_node(_aux->get_left_node());
		_node->set_right_node(_aux->get_right_node());
		delete _aux;
		return;
	}
	else {
		if (_parent->get_right_node() == _node) {
			_parent->set_right_node(NULL);
		}
		else if (_parent->get_left_node() == _node) {
			_parent->set_left_node(NULL);
		}
		else if (_node == this->_root) {
			this->_root = NULL;
		}
		delete _node;
		return;
	}
}

/**
 * @brief level
 * @tparam T 
 * @return int
*/
template<typename T>
int Binary_Tree<T>::level() {
	if (this->_is_empty()) {
		return -1;
	}
	else {
		return get_level(this->_root, -1, -1);
	}
}

/**
 * @brief height
 * @tparam T
 * @return int
*/
template<typename T>
int Binary_Tree<T>::height() {
	return level();
}

/**
 * @brief depth
 * @tparam T
 * @return int
*/
template<typename T>
int Binary_Tree<T>::depth() {
	return level();
}

/**
 * @brief level
 * @tparam T 
 * @param _data 
 * @return int
*/
template<typename T>
template<typename R>
int Binary_Tree<T>::level(R _data) {
	if (this->_is_empty()) {
		return -1;
	}
	else {
		return get_level(this->_root, 0, 0, _data);
	}
}

/**
 * @brief get_level
 * @tparam T 
 * @param _node 
 * @param _left 
 * @param _right 
 * @return int
*/
template<typename T>
int Binary_Tree<T>::get_level(Tree_Node<T>* _node, int _left, int _right) {
	if (_node == NULL) {
		return 0;
	}
	else {
		_left = get_level(_node->get_left_node(), _left, _right);
		_right = get_level(_node->get_right_node(), _left, _right);

		if (_left > _right) {
			return _left + 1;
		}
		else {
			return _right + 1;
		}
	}
}

/**
 * @brief get_level
 * @tparam T 
 * @param _node 
 * @param _level 
 * @param aux 
 * @param _data 
 * @return int
*/
template<typename T>
template<typename R>
int Binary_Tree<T>::get_level(Tree_Node<T>* _node, int _level, int aux , R _data) {
	if (_node == NULL) {
		return -1;
	}
	if (_node->get_data() == _data) {
		return _level;
	}
	if (_data < _node->get_data()) {
		return get_level(_node->get_left_node(), _level + 1, 0, _data);
	}
	else {
		return get_level(_node->get_right_node(), _level + 1, 0, _data);
	}
}

/**
 * @brief _get_root
 * @tparam T 
 * @return Tree_Node<T>*
*/
template<typename T>
Tree_Node<T>* Binary_Tree<T>::_get_root() {
	return this->_root;
}

/**
 * @brief _get_leaf_node
 * @tparam T
 * @param _node
 * @return Tree_Node<T>*
*/
template<typename T>
Tree_Node<T>* Binary_Tree<T>::_get_leaf_node(Tree_Node<T>* _node) {
	if (_node->get_right_node() != NULL) {
		return this->_get_leaf_node(_node->get_right_node());
	}
	else {
		return _node;
	}
}

/**
 * @brief to_string
 * @tparam T
 * @return string
*/
template<typename T>
string Binary_Tree<T>::to_string() {
	if (this->_root == NULL) {
		return "Vacio";
	}
	else {
		_in_order(this->_root);
		return "";
	}
}

/**
 * @brief print
 * @tparam T
*/
template<typename T>
void Binary_Tree<T>::print() {
	ostringstream oss;
	return print(this->_root, 0);
}

/**
 * @brief _pre_order
 * @tparam T
 * @return string
*/
template<typename T>
string Binary_Tree<T>::_pre_order() {
	if (this->_root == NULL) {
		return "Vacio";
	}
	else {
		_pre_order(this->_root);
		return "";
	}
}

/**
 * @brief _post_order
 * @tparam T
 * @return string
*/
template<typename T>
string Binary_Tree<T>::_post_order() {
	if (this->_root == NULL) {
		return "Vacio";
	}
	else {
		_post_order(this->_root);
		return "";
	}
}

/**
 * @brief _pre_order
 * @tparam T
 * @param _node
*/
template<typename T>
void Binary_Tree<T>::_pre_order(Tree_Node<T>* _node) {
	if (_node == NULL) {
		return;
	}
	else {
		cout << _node->get_data() << " - ";
		_pre_order(_node->get_left_node());
		_pre_order(_node->get_right_node());
	}
}

/**
 * @brief _in_order
 * @tparam T
 * @param _node
*/
template<typename T>
void Binary_Tree<T>::_in_order(Tree_Node<T>* _node) {
	if (_node == NULL) {
		return;
	}
	else {
		_in_order(_node->get_left_node());
		cout << _node->get_data() << " - ";
		_in_order(_node->get_right_node());
	}
}

/**
 * @brief _post_order
 * @tparam T
 * @param _node
*/
template<typename T>
void Binary_Tree<T>::_post_order(Tree_Node<T>* _node) {
	if (_node == NULL) {
		return;
	}
	else {
		_post_order(_node->get_left_node());
		_post_order(_node->get_right_node());
		cout << _node->get_data() << " - ";
	}
}

/**
 * @brief print
 * @tparam T
 * @param _node
 * @param cont
*/
template<typename T>
void Binary_Tree<T>::print(Tree_Node<T>* _node, int cont) {
	if (this->_is_empty()) {
		cout << "Arbol vacio" << endl;
		return;
	}
	if (_node == NULL) {
		return;
	}
	else {
		print(_node->get_right_node(), cont + 1);
		for (int i = 0; i < cont; i++) {
			cout << " ";
		}
		cout << _node->get_data() << endl;
		print(_node->get_left_node(), cont + 1);
	}
}

/**
 * @brief ~Binary_Tree
 * @tparam T
 * @return
*/
template<typename T>
Binary_Tree<T>::~Binary_Tree() {}
