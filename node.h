#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node
{
        Node();
        int data;
        Node *next;
        Node *previous;
};

#endif