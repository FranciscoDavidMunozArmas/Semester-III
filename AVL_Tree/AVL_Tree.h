#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>

#include "AVL_Node.h"

using namespace std;

template<class T>
class AVL_Tree
{
public:
    AVL_Tree();
    void _add(T _data);
    template<typename R>
    void _delete(R _data);
    template<typename R>
    T* _look(R _data);
    bool _is_empty();
    AVL_Node<T>* _get_root();
    string to_string();
    void _print();
    virtual ~AVL_Tree();
protected:
private:
    AVL_Node<T>* _root;

    void _add(AVL_Node<T>* _node,T _data);
    void _update_balance(AVL_Node<T>* _node, bool _added, bool _flag);
    void _rot_right(AVL_Node<T>* _node);
    void _rot_left(AVL_Node<T>* _node);
    int _height(AVL_Node<T>* _node, int _right, int _left);
    void _print(AVL_Node<T>* _node, int _count);
    template<typename R>
    void _delete(AVL_Node<T>* _node, R _data);
    void _remove_node(AVL_Node<T>* _node);
    AVL_Node<T>* _min_node(AVL_Node<T>* _node);
    template<typename R>
    T* _look(AVL_Node<T>* _node, R _data);
};

#endif
