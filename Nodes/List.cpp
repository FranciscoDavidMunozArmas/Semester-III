#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "List.h"
#include "Node.cpp"

#pragma once

using namespace std;

template<class T>
List<T>::List() {
	this->_next = NULL;
}

template<class T>
void List<T>::add_begin(T _data) {
    if (this->is_empty()) {
        this->_next = new Node<T>(_data, NULL);
    }
    else {
        Node<T>* aux = new Node<T>(_data, _next);
        this->_next = aux;
    }
}

template<class T>
void List<T>::add_end(T _data) {

    if (is_empty()) {
        this->_next = new Node<T>(_data, NULL);
    }
    else {
        Node<T>* aux = new Node<T>();
        Node<T>* aux_1 = new Node<T>();
        Node<T>* aux_2 = new Node<T>(_data, NULL);

        aux = this->_next;

        while (aux != NULL)
        {
            aux_1 = aux;
            aux = aux->_get_node();
        }

        aux_1->_set_node(aux_2);
    }
}

template<class T>
void List<T>::_delete_begin() {
    if (this->is_empty()) {
        cout << "No hay elementos" << endl;
        return;
    }
    
    Node<T>* aux = NULL;
    Node<T>* aux_1 = NULL;

    aux = this->_next;
    aux_1 = aux->_get_node();
    this->_next = aux_1;
    delete aux;
}

template<class T>
void List<T>::_delete_end() {
    if (this->is_empty()) {
        cout << "No hay elementos" << endl;
        return;
    }

    Node<T>* aux;
    Node<T>* aux_1 = NULL;
    Node<T>* aux_2 = NULL;

    aux = this->_next;

    while (aux != NULL)
    {
        aux_2 = aux_1;
        aux_1 = aux;
        aux = aux->_get_node();
    }

    if (aux_2 == NULL) {
        this->_next = NULL;
        delete aux_1;
    }
    else {
        aux_2->_set_node(aux_1->_get_node());
        delete aux_1;
    }
}

template<class T>
bool List<T>::is_empty() {
	return (this->_next == NULL) ? true : false;
}

template<class T>
void List<T>::_print_node() {
    Node<T>* aux = new Node<T>();
    aux = this->_next;
    while (aux != NULL) {
        cout << aux->_get_data() << " -> ";
        aux = aux->_get_node();
    }

    cout << "NULL" << endl;
}


template<class T>
string List<T>::to_string() {
    ostringstream oss;
    Node<T>* aux = new Node<T>();
    aux = this->_next;
    while (aux != NULL) {
        oss << aux->to_string();
        aux = aux->_get_node();
    }

    oss << "NULL";

    return oss.str();
}


template<class T>
List<T>::~List() {}
