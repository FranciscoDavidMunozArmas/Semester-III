#ifndef LIST_DOUBLE_H
#define LIST_DOUBLE_H

#include <iostream>

#include "Node_Double.h"

using namespace std;

template<class T>
class List_Double
{
public:
    List_Double();

    void add_begin(T _data);
    void add_end(T _data);
    void add_in(T _data, int position);

    void _delete_begin();
    void _delete_end();
    void _delete_in(int position);

    int _size();
    bool is_empty();

    string to_string();

    virtual ~List_Double();

protected:
private:
    Node_Double<T>* _node;
};

#endif
