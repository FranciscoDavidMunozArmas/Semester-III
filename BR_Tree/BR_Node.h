#ifndef BR_NODE_H
#define BR_NODE_H

#include <iostream>

using namespace std;

enum class BR_COLOR {
    BLACK, RED
};

template<class T>
class BR_Node
{
public:
    BR_Node();
    BR_Node(T _data, BR_Node* _left, BR_Node* _right, BR_Node* _parent, BR_COLOR _color);

    void set_data(T _data);
    void set_left_node(BR_Node* _left);
    void set_right_node(BR_Node* _right);
    void set_parent_node(BR_Node* _parent);
    void set_color(BR_COLOR _color);

    T get_data();
    BR_Node* get_right_node();
    BR_Node* get_left_node();
    BR_Node* get_parent_node();
    BR_COLOR get_color();
    int get_balance_factor();

    string to_string();

    virtual ~BR_Node();
protected:
private:
    BR_Node* _left;
    BR_Node* _right;
    BR_Node* _parent;
    BR_COLOR _color;
    T _data;
};

#endif
