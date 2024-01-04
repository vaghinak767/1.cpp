#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector
{
    private:
        int m_size;
        int m_capacity;
        int *arr;
        void resize();
    public:
        Vector();
        Vector(int);
        Vector(const Vector&);
        Vector(int, int );
        //Vector(int first, int last);
        Vector(std::initializer_list<int>);
        int size();
        int capacity();
        bool empty();
        int at(int);
        void push_back(int);
        void pop_back();
        int *data();
        void clear();
        void insert(int, int);
        Vector& operator=(const Vector& );
        void display();
        void swap(Vector&);
        void assign(int, const int&);
        int operator[](int);
        int front();
        int back();
        int* begin();
        int* end();
        void revers();
        void resize(int);
        void erase(int);
        void erase(int, int);
        ~Vector();
};

#endif
