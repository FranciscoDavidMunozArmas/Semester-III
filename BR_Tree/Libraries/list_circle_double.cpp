/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of List_Circle_Double
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "List_Circle_Double.h"
#include "Node_Double.cpp"
#include "Array_dinamic.cpp"

#pragma once

using namespace std;

/**
 * @brief List_Circle_Double
 * @tparam T
 * @return
*/
template<class T>
List_Circle_Double<T>::List_Circle_Double() {
	this->_node = NULL;
    this->_end = NULL;
}

/**
 * @brief add_begin
 * @tparam T
 * @param _data
*/
template<class T>
void List_Circle_Double<T>::add_begin(T _data) {
    if (this->is_empty()) {
        this->_node = new Node_Double<T>(_data, this->_end, this->_end);
        this->_end = this->_node;
    }
    else {
        Node_Double<T>* aux = new Node_Double<T>(_data, _node, this->_end);
        this->_node->_set_back_node(aux);
        this->_end->_set_next_node(aux);
        this->_node = aux;
    }
}

/**
 * @brief add_end
 * @tparam T
 * @param _data
*/
template<class T>
void List_Circle_Double<T>::add_end(T _data) {

    if (is_empty()) {
        this->_node = new Node_Double<T>(_data, this->_end, this->_end);
        this->_end = this->_node;
    }
    else {
        Node_Double<T>* aux = new Node_Double<T>(_data, this->_node, this->_end);
        this->_end->_set_next_node(aux);
        this->_node->_set_back_node(aux);
        this->_end = aux;
    }
}

/**
 * @brief add_in
 * @tparam T
 * @param _data
 * @param position
*/
template<class T>
void List_Circle_Double<T>::add_in(T _data, int position) {
    if (is_empty()) {
        this->_node = new Node_Double<T>(_data, this->_end, this->_end);
        this->_end = this->_node;
    }
    else if (position <= 0 || this->_size() - 1 <= position) {
        if (position == 0) {
            this->add_begin(_data);
        }
        else if (position == this->_size() - 1) {
            this->add_end(_data);
        }
        else {
            cout << "Fuera de rango" << endl;
        }
        system("pause");
    }
    else {
        Node_Double<T>* aux = this->_node;

        int _index_position = 0;
        while (aux != this->_end && _index_position != position)
        {
            aux = aux->_get_next_node();
            _index_position++;
        }

        Node_Double<T>* aux_1 = new Node_Double<T>(_data, aux, aux->_get_back_node());

        aux->_get_back_node()->_set_next_node(aux_1);
        aux->_set_back_node(aux_1);
    }
}

/**
 * @brief _size
 * @tparam T
 * @return int
*/
template<class T>
int List_Circle_Double<T>::_size() {
    Node_Double<T>* aux = new Node_Double<T>();
    Node_Double<T>* aux_1 = new Node_Double<T>();

    aux = this->_node;

    int _index_position = 0;
    while (aux != this->_end)
    {
        _index_position++;
        aux_1 = aux;
        aux = aux->_get_next_node();
    }
    if (aux == this->_end && aux != NULL) {
        _index_position++;
    }

    return _index_position;
}

/**
 * @brief _delete_begin
 * @tparam T
*/
template<class T>
void List_Circle_Double<T>::_delete_begin() {
    if (this->is_empty()) {
        cout << "No hay elementos" << endl;
        return;
    }

    if (this->_node == this->_end) {
        this->_node = NULL;
        this->_end = _node;
    }
    else {
        Node_Double<T>* aux = this->_node;
        Node_Double<T>* aux_1 = aux->_get_next_node();

        aux_1->_set_back_node(this->_end);
        this->_end->_set_next_node(aux_1);
        this->_node = aux_1;
        delete aux;
    }
}

/**
 * @brief _delete_end
 * @tparam T
*/
template<class T>
void List_Circle_Double<T>::_delete_end() {
    if (this->is_empty()) {
        cout << "No hay elementos" << endl;
        return;
    }

    if (this->_node == this->_end) {
        this->_node = NULL;
        this->_end = _node;
    }
    else {
        Node_Double<T>* aux = this->_end;
        Node_Double<T>* _back_node = aux->_get_back_node();
        _back_node->_set_next_node(this->_node);
        this->_end = _back_node;
        delete aux;
    }
}

/**
 * @brief _delete_in
 * @tparam T
 * @param position
*/
template<class T>
void List_Circle_Double<T>::_delete_in(int position) {

    if (is_empty()) {
        cout << "No hay elementos" << endl;
        return;
    }
    else if (position <= 0 || this->_size() - 1<= position) {
        if (position == 0) {
            this->_delete_begin();
        }
        else if (position == this->_size() - 1) {
            this->_delete_end();
        }
        else {
            cout << "Fuera de rango" << endl;
        }
        system("pause");
    }
    else {
        Node_Double<T>* aux = this->_node;

        int _index_position = 0;
        while (aux != this->_end && _index_position != position)
        {
            aux = aux->_get_next_node();
            _index_position++;
        }

        if (aux == this->_end) {
            this->_node = NULL;
            this->_end = this->_node;
        }
        else {
            Node_Double<T>* _next_node = aux->_get_next_node();
            Node_Double<T>* _back_node = aux->_get_back_node();
            _back_node->_set_next_node(_next_node);
            _next_node->_set_back_node(_back_node);
            delete aux;
        }
    }
}

/**
 * @brief _array_to_list
 * @tparam T
 * @param _array
 * @return List_Circle_Double<T>
*/
template<class T>
List_Circle_Double<T> List_Circle_Double<T>::_array_to_list(T* _array) {
    Array_dynamic _ad;
    for (int i = 0; i < _ad._dynamic_size(_array); i++) {
        this->add_end(*(_array + i));
    }

    return *this;
}

/**
 * @brief _get_node
 * @tparam T
 * @return Node_Double<T>*
*/
template<class T>
Node_Double<T>* List_Circle_Double<T>::_get_node() {
    return this->_node;
}

/**
 * @brief _get_end_node
 * @tparam T
 * @return Node_Double<T>*
*/
template<class T>
Node_Double<T>* List_Circle_Double<T>::_get_end_node() {
    return this->_end;
}

/**
 * @brief is_empty
 * @tparam T
 * @return bool
*/
template<class T>
bool List_Circle_Double<T>::is_empty() {
	return (this->_node == NULL) ? true : false;
}

/**
 * @brief to_string
 * @tparam T
 * @return string
*/
template<class T>
string List_Circle_Double<T>::to_string() {
    ostringstream oss;
    Node_Double<T>* aux = this->_node;

    oss << "Repite";

    if (this->_node == NULL) {
        oss << "NULL";
    }
    else {
        while (aux != this->_end) {
            oss << " <- " << aux->to_string() << " -> ";
            aux = aux->_get_next_node();
        }

        oss << " <- " << this->_end->to_string() << " -> Repite";

        return oss.str();
    }

    return oss.str();
}

/**
 * @brief get_in
 * @tparam T
 * @param _index
 * @return T
*/
template<class T>
T List_Circle_Double<T>::get_in(int _index) {
    if (this->_size() <= _index) {
        T _non;
        return _non;
    }

    int _index_aux = 0;
    Node_Double<T>* _aux = this->_node;
    while ((_aux != this->_end)&&(_index_aux != _index)) {
        _aux = _aux->_get_next_node();
        _index_aux++;
    }
    return _aux->_get_data();
}

/**
 * @brief ~List_Circle_Double
 * @tparam T
 * @return
*/
template<class T>
List_Circle_Double<T>::~List_Circle_Double() {}
