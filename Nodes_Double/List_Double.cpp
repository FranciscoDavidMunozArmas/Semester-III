#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "List_Double.h"
#include "Node_Double.cpp"

#pragma once

using namespace std;

template<class T>
List_Double<T>::List_Double() {
	this->_node = NULL;
}

template<class T>
void List_Double<T>::add_begin(T _data) {
    if (this->is_empty()) {
        this->_node = new Node_Double<T>(_data, NULL, NULL);
    }
    else {
        Node_Double<T>* aux = new Node_Double<T>(_data, _node, NULL);
        this->_node->_set_back_node(aux);
        this->_node = aux;
    }
}

template<class T>
void List_Double<T>::add_end(T _data) {

    if (is_empty()) {
        this->_node = new Node_Double<T>(_data, NULL, NULL);
    }
    else {
        Node_Double<T>* aux = new Node_Double<T>();
        Node_Double<T>* aux_1 = new Node_Double<T>();

        aux = this->_node;

        while (aux != NULL)
        {
            aux_1 = aux;
            aux = aux->_get_next_node();
        }

        Node_Double<T>* aux_2 = new Node_Double<T>(_data, aux_1->_get_next_node(), aux_1);

        aux_1->_set_next_node(aux_2);
    }
}

template<class T>
void List_Double<T>::add_in(T _data, int position) {
    if (is_empty()) {
        this->_node = new Node_Double<T>(_data, NULL, NULL);
    }
    else if (position <= 1 || this->_size() < position) {
        if (position == 1) {
            this->add_begin(_data);
        }
        else if (position == this->_size() + 1) {
            this->add_end(_data);
        }
        else {
            cout << "Fuera de rango" << endl;
        }
        system("pause");
    }
    else {
        Node_Double<T>* aux = new Node_Double<T>();
        Node_Double<T>* aux_1 = new Node_Double<T>();

        aux = this->_node;

        int _index_position = 0;
        while (aux != NULL && _index_position != position)
        {
            aux_1 = aux;
            aux = aux->_get_next_node();
            _index_position++;
        }
        Node_Double<T>* _back_node = aux_1->_get_back_node();
        Node_Double<T>* aux_2 = new Node_Double<T>(_data, aux_1, _back_node);

        _back_node->_set_next_node(aux_2);
        aux_1->_set_back_node(aux_2);
    }
}

template<class T>
int List_Double<T>::_size() {
    Node_Double<T>* aux = new Node_Double<T>();
    Node_Double<T>* aux_1 = new Node_Double<T>();

    aux = this->_node;

    int _index_position = 0;
    while (aux != NULL)
    {
        _index_position++;
        aux_1 = aux;
        aux = aux->_get_next_node();
    }

    return _index_position;
}

template<class T>
void List_Double<T>::_delete_begin() {
    if (this->is_empty()) {
        cout << "No hay elementos" << endl;
        return;
    }

    Node_Double<T>* aux = NULL;
    Node_Double<T>* aux_1 = NULL;

    aux = this->_node;
    aux_1 = aux->_get_next_node();
    this->_node = aux_1;
    delete aux;
}

template<class T>
void List_Double<T>::_delete_end() {
    if (this->is_empty()) {
        cout << "No hay elementos" << endl;
        return;
    }

    Node_Double<T>* aux;
    Node_Double<T>* aux_1 = NULL;
    Node_Double<T>* aux_2 = NULL;

    aux = this->_node;

    while (aux != NULL)
    {
        aux_2 = aux_1;
        aux_1 = aux;
        aux = aux->_get_next_node();
    }

    if (aux_2 == NULL) {
        this->_node = NULL;
        delete aux_1;
    }
    else {
        aux_2->_set_next_node(aux_1->_get_next_node());
        delete aux_1;
    }
}

template<class T>
void List_Double<T>::_delete_in(int position) {

    if (is_empty()) {
        cout << "No hay elementos" << endl;
        return;
    }
    else if (position <= 1 || this->_size() < position) {
        cout << "Fuera de rango" << endl;
        system("Pause");
        return;
    }
    else {
        Node_Double<T>* aux;
        Node_Double<T>* aux_1 = NULL;

        aux = this->_node;
        int _index_position = 0;

        while (aux != NULL && _index_position != position)
        {
            aux_1 = aux;
            aux = aux->_get_next_node();
            _index_position++;
        }

        Node_Double<T>* _next_node = aux_1->_get_next_node();
        Node_Double<T>* _back_node = aux_1->_get_back_node();
        if (_back_node == NULL) {
            _next_node->_set_back_node(NULL);
            this->_node = _next_node;
            delete aux_1;
        }
        else {
            _back_node->_set_next_node(_next_node);
            _next_node->_set_back_node(_back_node);
            aux_1 = NULL;
            delete aux_1;
        }
    }
}

template<class T>
bool List_Double<T>::is_empty() {
	return (this->_node == NULL) ? true : false;
}

template<class T>
string List_Double<T>::to_string() {
    ostringstream oss;
    Node_Double<T>* aux = new Node_Double<T>();
    aux = this->_node;
    if (!this->is_empty()) {
        oss << "NULL ";
    }
    while (aux != NULL) {
        oss << aux->to_string();
        aux = aux->_get_next_node();
    }

    oss << "NULL";

    return oss.str();
}


template<class T>
List_Double<T>::~List_Double() {}
