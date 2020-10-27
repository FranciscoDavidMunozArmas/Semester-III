/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of List_Circle_Double
*/

#ifndef LIST_CIRCLE_DOUBLE_H
#define LIST_CIRCLE_DOUBLE_H

#include <iostream>

#include "Node_Double.h"

using namespace std;

template<class T>
class List_Circle_Double
{
public:
    List_Circle_Double();

    void add_begin(T _data);
    void add_end(T _data);
    void add_in(T _data, int position);

    void _delete_begin();
    void _delete_end();
    void _delete_in(int position);

    T get_in(int _index);

    Node_Double<T>* _get_node();
    Node_Double<T>* _get_end_node();

    List_Circle_Double _array_to_list(T* _array);

    int _size();
    bool is_empty();

    string to_string();

    virtual ~List_Circle_Double();

protected:
private:
    Node_Double<T>* _node;
    Node_Double<T>* _end;
};

#endif
