#ifndef AVL_NODE_H
#define AVL_NODE_H

#include <iostream>

using namespace std;

template<class T>
class AVL_Node
{
public:
    AVL_Node();
    AVL_Node(T _data, AVL_Node* _left, AVL_Node* _right, AVL_Node* _parent);

    void set_data(T _data);
    void set_left_node(AVL_Node* _left);
    void set_right_node(AVL_Node* _right);
    void set_parent_node(AVL_Node* _parent);
    void set_balance_factor(int _balance_factor);
    void add_balance_factor(int _balance_factor);

    T get_data();
    AVL_Node* get_right_node();
    AVL_Node* get_left_node();
    AVL_Node* get_parent_node();
    int get_balance_factor();

    string to_string();

    virtual ~AVL_Node();
protected:
private:
    AVL_Node* _left;
    AVL_Node* _right;
    AVL_Node* _parent;
    T _data;
    int _balance_factor;
};

#endif
