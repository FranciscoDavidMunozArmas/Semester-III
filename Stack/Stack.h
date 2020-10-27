#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include <string>

#include "Node.h"

using namespace std;

template<class T>
class Stack
{
public:
    Stack();
    void _push(T _data);
    T _pop();
    void _clear_all();
    bool _is_empty();
    T _top();

	string to_string();


    virtual ~Stack();
protected:
private:
    Node<T>* _node;
};

#endif
