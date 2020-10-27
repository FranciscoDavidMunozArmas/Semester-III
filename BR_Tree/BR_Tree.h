#ifndef BR_TREE_H
#define BR_TREE_H

#include <iostream>

#include "BR_Node.h"

#include "Libraries/Screen.h"

using namespace std;

template<class T>
class BR_Tree
{
public:
    BR_Tree();
    void _add(T _data);
    template<typename R>
    void _delete(R _data);
    template<typename R>
    T* _look(R _data);
    bool _is_empty();
    BR_Node<T>* _get_root();
    string to_string();
    void _print();
    virtual ~BR_Tree();
protected:
private:
    BR_Node<T>* _root;
    Screen _screen;

    void _add(BR_Node<T>* _node,T _data);
    void _update_balance(BR_Node<T>* _node, bool _added, bool _flag);
    void _rot_right(BR_Node<T>* _node);
    void _rot_left(BR_Node<T>* _node);
    void _add_case_1(BR_Node<T>* _node);
    void _add_case_2(BR_Node<T>* _node);
    void _add_case_3(BR_Node<T>* _node);
    void _add_case_4(BR_Node<T>* _node);
    void _add_case_5(BR_Node<T>* _node);
    void _delete_case_1(BR_Node<T>* _node);
    void _delete_case_2(BR_Node<T>* _node);
    void _delete_case_3(BR_Node<T>* _node);
    void _delete_case_4(BR_Node<T>* _node);
    void _delete_case_5(BR_Node<T>* _node);
    int _height(BR_Node<T>* _node, int _right, int _left);
    void _print(BR_Node<T>* _node, int _count);
    template<typename R>
    void _delete(BR_Node<T>* _node, R _data);
    void _remove_node(BR_Node<T>* _node);
    BR_Node<T>* _min_node(BR_Node<T>* _node);
    template<typename R>
    T* _look(BR_Node<T>* _node, R _data);
};

#endif
