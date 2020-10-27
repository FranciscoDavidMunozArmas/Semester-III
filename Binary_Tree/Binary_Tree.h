/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date viernes, 21 de agosto de 2020 10:07:14
 * @function Declaration Binary_Tree
*/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <sstream>

#include "Tree.cpp"
#include "Tree_Node.h"

using namespace std;

template<class T>
class Binary_Tree : public Tree<T>
{
public:
    Binary_Tree() : Tree<T>() {};
    void _add(T _data);
    template<typename R>
    void _delete(R _data);
    template<typename R>
    T* _look(R _data);
    int level();
    template<typename R>
    int level(R _data);
    int height();
    int depth();
    Tree_Node<T>* _get_root();
    string to_string();
    string _pre_order();
    string _post_order();
    void print();
    virtual ~Binary_Tree();
protected:
private:
    void _add(Tree_Node<T>* _node, T _data);
    template<typename R>
    T* _look(Tree_Node<T>* _node, R _data);
    template<typename R>
    void _delete(Tree_Node<T>* _node, Tree_Node<T>* _parent, R _data);
    void _delete_node(Tree_Node<T>* _node, Tree_Node<T>* _parent);
    Tree_Node<T>* _get_leaf_node(Tree_Node<T>* _node);
    int get_level(Tree_Node<T>* _node, int _left, int _right);
    template<typename R>
    int get_level(Tree_Node<T>* _node, int _level, int aux, R _data);
    void _pre_order(Tree_Node<T>* _node);
    void _in_order(Tree_Node<T>* _node);
    void _post_order(Tree_Node<T>* _node);
    void print(Tree_Node<T>* _node, int cont);
};

#endif
