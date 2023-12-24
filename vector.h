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
        Vector()
        { 
            m_size = 0;
            arr = new int[m_size + 1];
            arr[0] = 0;
        }
        Vector(int size)
        {
            m_size = 0;
            arr = new int[size];
            m_capacity = size;
        }
        Vector(const Vector& obj)
        {
            m_size = obj.m_size;
            m_capacity = obj.m_capacity;
            arr = obj.arr;
        }
        int size();
        int capacity();
        bool empty();
        int at(int index);
        void push_back(int value);
        void pop_back();
        int *data();
        void clear();
        void insert(int index, int value);
        Vector& operator=(const Vector& other);
        void display();
        ~Vector()
        {
            delete[] arr;
        }
};

#endif