#ifndef TREE_H
#define TREE_H

#include <iostream>

#include "Tree_Node.h"

using namespace std;

template<class T>
class Tree
{
public:
    Tree();
    virtual void _add(T _data) = 0;
    bool _is_empty();
    virtual string to_string() = 0;
    virtual ~Tree();
protected:
    Tree_Node<T>* _root;
private:
};

#endif
