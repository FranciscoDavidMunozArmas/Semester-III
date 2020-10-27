#ifndef NODE_DOUBLE_H
#define NODE_DOUBLE_H

#include <iostream>

using namespace std;

template<class T>
class Node_Double
{
public:
    Node_Double();
    Node_Double(T _data, Node_Double* _next, Node_Double* _back);

    void _set_data(T _data);
    void _set_next_node(Node_Double* _node);
    void _set_back_node(Node_Double* _node);
    
    T _get_data();
    Node_Double* _get_next_node();
    Node_Double* _get_back_node();

    string to_string();

    virtual ~Node_Double();

protected:
private:
    T data;
    Node_Double* _next;
    Node_Double* _back;
};

#endif
