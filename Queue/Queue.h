#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

#include "Node.h"

using namespace std;

template<class T>
class Queue
{
public:
    Queue();

    void enqueue(T _data);
    T dequeue();
    bool _is_empty();
    void _clear_all();

    T _head_queue();

    string to_string();

    virtual ~Queue();
protected:
private:
    Node<T>* _head;
    Node<T>* _tail;
};

#endif