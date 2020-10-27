/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 25 de julio de 2020 17:16:14
 * @function Declaration of Reverse_Polish
*/

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cmath>

#include "Libraries/Verify_number.cpp"
#include "Libraries/Stack.cpp"
#include "Libraries/Tree_Node.cpp"
#include "Libraries/To_number.cpp"

#include "Reverse_Polish.h"

#pragma once

using namespace std;

/**
 * @brief Reverse_Polish
 * @return
*/
Reverse_Polish::Reverse_Polish() {
	this->_root = NULL;
	bool _has_variable = true;
}

/**
 * @brief Reverse_Polish
 * @param _expression
 * @return
*/
Reverse_Polish::Reverse_Polish(string _expression) {
	this->_root = NULL;
	bool _has_variable = true;
	_expression = _adjust_expression(_expression);
	_add_to_tree(_expression, _expression.length(), 0);
}

/**
 * @brief _set_expression
 * @param _expression
*/
void Reverse_Polish::_set_expression(string _expression) {
	_expression = _adjust_expression(_expression);
	_add_to_tree(_expression, _expression.length(), 0);
}

/**
 * @brief _add_to_tree
 * @param _expression
 * @param _size
 * @param _count
*/
void Reverse_Polish::_add_to_tree(string _expression, int _size, int _count) {
	if (_count == _size) {
		this->_root = this->_stack._pop();
		return;
	}
	if (_is_number(_expression.at(_count)) || _is_letter(_expression.at(_count))) {
		_stack._push(new Tree_Node<char>(_expression.at(_count), NULL, NULL));
	}
	else if (this->is_operator(_is_letter(_expression.at(_count)))) {
		Tree_Node<char>* _right = this->_stack._pop();
		Tree_Node<char>* _left = NULL;
		if (!this->_stack._is_empty()) {
			_left = this->_stack._pop();
		}
		this->_stack._push(new Tree_Node<char>(_expression.at(_count), _left, _right));
	}
	_add_to_tree(_expression ,_size, _count + 1);
}

/**
 * @brief _adjust_expression
 * @param _expression
 * @return string
*/
string Reverse_Polish::_adjust_expression(string _expression) {
	Stack<char> _stack_adjust;
	_expression = '(' + _expression + ')';
	ostringstream oss;
	for (char _data : _expression) {
		if (_is_number(_data) || _is_letter(_data)) {
			oss << _data;
		}
		else if (_data == '(') {
			_stack_adjust._push(_data);
		}
		else if (_data == ')') {
			while (_stack_adjust._top() != '(') {
				oss << _stack_adjust._pop();
			}
			_stack_adjust._pop();
		}
		else {
			if (is_operator(_data)) {
				while (_priotity(_data) <= _priotity(_stack_adjust._top())) {
					oss << _stack_adjust._pop();
				}
				_stack_adjust._push(_data);
			}
		}
	}
	return oss.str();
}

/**
 * @brief _invert
 * @param _expression
 * @return string
*/
string Reverse_Polish::_invert(string _expression) {
	ostringstream oss;
	for (int i = _expression.length() - 1; i >= 0; i--) {
		oss << _expression.at(i);
	}
	return oss.str();
}

/**
 * @brief _pre_order
*/
void Reverse_Polish::_pre_order() {
	if (this->_root == NULL) {
		cout << "Vacio" << endl;
	}
	else {
		_pre_order(this->_root);
		cout << endl;
	}
}

/**
 * @brief _in_order
*/
void Reverse_Polish::_in_order() {
	if (this->_root == NULL) {
		cout << "Vacio" << endl;
	}
	else {
		_in_order(this->_root);
		cout << endl;
	}
}

/**
 * @brief _post_order
*/
void Reverse_Polish::_post_order() {
	if (this->_root == NULL) {
		cout << "Vacio" << endl;
	}
	else {
		_post_order(this->_root);
		cout << endl;
	}
}

/**
 * @brief _pre_order
 * @param _node
*/
void Reverse_Polish::_pre_order(Tree_Node<char>* _node) {
	if (_node == NULL) {
		return;
	}
	else {
		cout << _node->get_data();
		_pre_order(_node->get_left_node());
		_pre_order(_node->get_right_node());
	}
}

/**
 * @brief _in_order
 * @param _node
*/
void Reverse_Polish::_in_order(Tree_Node<char>* _node) {
	if (_node == NULL) {
		return;
	}
	else {
		_in_order(_node->get_left_node());
		cout << _node->get_data();
		_in_order(_node->get_right_node());
	}
}

/**
 * @brief _post_order
 * @param _node
*/
void Reverse_Polish::_post_order(Tree_Node<char>* _node) {
	if (_node == NULL) {
		return;
	}
	else {
		_post_order(_node->get_left_node());
		_post_order(_node->get_right_node());
		cout << _node->get_data();
	}
}

/**
 * @brief print
*/
void Reverse_Polish::print() {
	print(this->_root, 0);
}

/**
 * @brief print
 * @param _node
 * @param cont
*/
void Reverse_Polish::print(Tree_Node<char>* _node, int cont) {
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
 * @brief _priotity
 * @param _operator
 * @return int
*/
int Reverse_Polish::_priotity(char _operator) {
	if (_operator == '-' || _operator == '+') {
		return 1;
	}
	else if (_operator == '*' || _operator == '/') {
		return 2;
	}
	else if (_operator == '^') {
		return 3;
	}
	else {
		return 0;
	}
}

/**
 * @brief _solve
*/
void Reverse_Polish::_solve() {
	if (this->_has_variable) {
		cout << "Operacion con variable, no se puede resolver" << endl;
		this->_in_order();
	}
	else {
		cout << "Solucion: " << _solve(this->_root);
	}
}

/**
 * @brief _solve
 * @param _node 
 * @return double
*/
double Reverse_Polish::_solve(Tree_Node<char>* _node) {
	if (_node == NULL) {
		return 0;
	}
	else {
		if (_node->get_left_node() == NULL && _node->get_right_node() == NULL) {
			return to_int(_node->get_data());
		}
		else {
			return _operate(_node->get_data(), _solve(_node->get_left_node()), _solve(_node->get_right_node()));
		}
	}
}

/**
 * @brief _operate
 * @param _operator 
 * @param _num_1 
 * @param _num_2 
 * @return double
*/
double Reverse_Polish::_operate(char _operator, double _num_1, double _num_2) {
	double solution = 0;
	switch (_operator)
	{
	case '+':
	{
		solution = _num_1 + _num_2;
	}break;
	case '-':
	{
		solution = _num_1 - _num_2;
	}break;
	case '*':
	{
		solution = _num_1 * _num_2;
	}break;
	case '/':
		{
		if (_num_2 != 0) {
			solution = _num_1 / _num_2;
		}
		}break;
	case '^':
	{
		solution = pow(_num_1, _num_2);
	}break;
	}
	return solution;
}

/**
 * @brief is_operator
 * @param _operator
 * @return bool
*/
bool Reverse_Polish::is_operator(char _operator) {
	return (!_is_letter(_operator) && !_is_number(_operator) && _operator != '(' && _operator != ')');
}

/**
 * @brief is_infix
 * @param _expression
 * @return bool
*/
bool Reverse_Polish::is_infix(string _expression) {
	int _left = 0;
	int _right = 0;
	int _first = 0;
	int _last = _expression.length() - 1;

	for (char _aux : _expression) {
		if (_first == 0) {
			if (is_operator(_aux) && _aux != '(') {
				return false;
			}
		}
		else if (_first == _last) {
			if (is_operator(_aux) && _aux != ')') {
				return false;
			}
		}

		if (_is_number(_aux)) {
			this->_has_variable = false;
		}

		if (_aux < 40 || _aux == 44 || _aux == 46 || (57 < _aux && _aux < 65) || (90 < _aux && _aux < 94) || (94 < _aux && _aux < 97) || (122 < _aux)) {
			return false;
		}

		if (_aux == 40) {
			_left++;
		}
		else if (_aux == 41) {
			_right++;
		}

		_first++;
	}
	for (int i = 0; i < _last; i++) {
		if (is_operator(_expression.at(i))) {
			if (is_operator(_expression.at(i)) && is_operator(_expression.at(i + 1))) {
				return false;
			}
		}
	}
	if (_left != _right) {
		return false;
	}
	return true;
}

/**
 * @brief ~Reverse_Polish
 * @return
*/
Reverse_Polish::~Reverse_Polish() {
	this->_root = NULL;
}
