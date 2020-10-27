#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "List_Circle.h"
#include "Node.cpp"

#pragma once

using namespace std;

template<class T>
List_Circle<T>::List_Circle() {
	this->_next = NULL;
    this->_end = NULL;
}

template<class T>
void List_Circle<T>::add_begin(T _data) {
    if (this->is_empty()) {
        this->_next = new Node<T>(_data, this->_end);
        this->_end = this->_next;
    }
    else {
        Node<T>* aux = new Node<T>(_data, this->_next);
        this->_end->_set_node(aux);
        this->_next = aux;
    }
}

template<class T>
void List_Circle<T>::add_end(T _data) {

    if (is_empty()) {
        this->_next = new Node<T>(_data, this->_end);
        this->_end = this->_next;
    }
    else {
        Node<T>* aux = this->_next;
        Node<T>* aux_1 = new Node<T>(_data, this->_next);
        this->_end->_set_node(aux_1);
        _end = aux_1;
    }
}

template<class T>
void List_Circle<T>::_delete_begin() {
    if (this->is_empty()) {
        cout << "No hay elementos" << endl;
        return;
    }

    Node<T>* aux = this->_next;
    Node<T>* aux_1 = aux->_get_node();

    this->_next = aux_1;
    delete aux;
}

template<class T>
void List_Circle<T>::_delete_end() {
    if (this->is_empty()) {
        cout << "No hay elementos" << endl;
        return;
    }

    Node<T>* aux = this->_next;
    Node<T>* aux_1 = NULL;
    Node<T>* aux_2 = NULL;

    while (aux != this->_end)
    {
        aux_2 = aux_1;
        aux_1 = aux;
        aux = aux->_get_node();
    }

    if (aux_2 == NULL) {
        this->_next = NULL;
        this->_end = this->_next;
        delete aux_1;
    }
    else {
        this->_end->_set_data(aux_1->_get_data());
        aux_2->_set_node(this->_end);
        delete aux_1;
    }
}

template<class T>
bool List_Circle<T>::is_empty() {
	return (this->_next == NULL) ? true : false;
}

template<class T>
string List_Circle<T>::to_string() {
    ostringstream oss;
    Node<T>* aux = this->_next;

    if (this->_next == NULL) {
        oss << "NULL";
    }
    else {
        while (aux != this->_end) {
            oss << aux->to_string();
            aux = aux->_get_node();
        }

        oss << this->_end->to_string() << "Repite";

        return oss.str();
    }
}


template<class T>
List_Circle<T>::~List_Circle() {}
