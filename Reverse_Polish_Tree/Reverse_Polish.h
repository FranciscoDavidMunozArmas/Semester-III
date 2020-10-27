/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 25 de julio de 2020 17:16:14
 * @function Declaration of Reverse_Polish
*/

#ifndef REVERSE_POLISH_H
#define REVERSE_POLISH_H

#include <iostream>
#include "Libraries/Stack.h"
#include "Libraries/Tree_Node.h"

using namespace std;

class Reverse_Polish
{
public:
    Reverse_Polish();
    Reverse_Polish(string _expression);
    void _set_expression(string _expression);

    void _pre_order();
    void _in_order();
    void _post_order();
    void print();
    int _priotity(char _operator);
    bool is_infix(string _expression);

    void _solve();

    virtual ~Reverse_Polish();
protected:
private:
    bool is_operator(char _operator);
    void _add_to_tree(string _expression, int _size, int _count);
    string _adjust_expression(string _expression);
    void _pre_order(Tree_Node<char>* _node);
    void _in_order(Tree_Node<char>* _node);
    void _post_order(Tree_Node<char>* _node);
    void print(Tree_Node<char>* _node, int cont);
    double _operate(char _operator, double _num_1, double _num_2);
    double _solve(Tree_Node<char>* _node);
    string _invert(string _expression);
    Stack<Tree_Node<char>*> _stack;
    Tree_Node<char>* _root;
    bool _has_variable;
};

#endif
