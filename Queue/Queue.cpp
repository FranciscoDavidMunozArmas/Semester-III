#include <iostream>
#include <sstream>

#include "Queue.h"
#include "Node.cpp"

using namespace std;

template<class T>
Queue<T>::Queue() {
	this->_head = this->_tail = NULL;
}

template<class T>
void Queue<T>::enqueue(T _data) {
	if (_is_empty()) {
		this->_head = new Node<T>(_data, NULL);
		this->_tail = this->_head;
	}
	else {
		Node<T>* _aux = new Node<T>(_data, NULL);
		this->_tail->_set_node(_aux);
		this->_tail = _aux;
	}
}

template<class T>
T Queue<T>::dequeue() {
	if (_is_empty()) {
		throw "Cola Vacia";
	}
	else {
		T _aux_data = this->_head->_get_data();
		Node<T>* _aux_node = this->_head;
		this->_head = this->_head->_get_node();
		delete _aux_node;
		return _aux_data;
	}
}

template<class T>
bool Queue<T>::_is_empty() {
	return (this->_head == NULL) ? true : false;
}

template<class T>
T Queue<T>::_head_queue() {
	if (_is_empty()) {
		cout << "Cola Vacia" << endl;
	}
	else {
		return this->_head->_get_data();
	}
}

template<class T>
void Queue<T>::_clear_all() {
	Node<T>* _aux;
	while (this->_head != NULL) {
		_aux = this->_head;
		this->_head = this->_head->_get_node();
		delete _aux;
	}
}

template<class T>
string Queue<T>::to_string() {
	Node<T>* _aux = this->_head;
	ostringstream oss;
	oss << "Head -> ";
	while (_aux != NULL) {
		oss << _aux->to_string();
		_aux = _aux->_get_node();
	}

	oss << "Tail";
	return oss.str();
}

template<class T>
Queue<T>::~Queue() {
	_clear_all();
}
