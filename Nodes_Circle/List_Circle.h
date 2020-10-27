#ifndef LIST_CIRCLE_H
#define LIST_CIRCLE_H

#include <iostream>

#include "Node.h"

using namespace std;

template<class T>
class List_Circle
{
public:
    List_Circle();

    void add_begin(T _data);
    void add_end(T _data);
    void _delete_begin();
    void _delete_end();

    bool is_empty();

    string to_string();

    virtual ~List_Circle();

protected:
private:
    Node<T>* _next;
    Node<T>* _end;
};

#endif
