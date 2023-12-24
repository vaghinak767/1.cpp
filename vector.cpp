#include "vector.h"

int Vector::size()
{
    return m_size; 
}

int Vector::capacity()
{
    return m_capacity;
}

bool Vector::empty()
{
    if(m_size == 0)
    {
        return false;
    }
    return true;
}

int Vector::at(int index)
{
    if(index >= m_size)
    {
        return -1;
    }
    return arr[index];
}

void Vector::push_back(int value)
{
    if(m_size == m_capacity)
    {
        m_capacity *= 2;
        int *tmp = new int[m_capacity];
        for(int i = 0; i < m_size; ++i)
        {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
    }
    arr[m_size] = value;
    ++m_size;
}

void Vector::pop_back()
{
    arr[m_size - 1] = 0;
    --m_size;
}

int* Vector::data()
{
    return arr;
}

void Vector::clear()
{
    delete[] arr;
    arr = nullptr;
    m_size = 0;
    m_capacity = 0;
}

void Vector::insert(int index, int value)
{
    if(index >= m_capacity)
    {
        return;
    }
    if(m_size == m_capacity)
    {
        m_capacity *= 2;
    }
    int *tmp = new int[m_capacity];
    for(int i = 0; i < index; ++i)
    {
        tmp[i] = arr[i];
    }
    tmp[index] = value;
    for(int i = index + 1; i < m_size + 1; ++i)
    {
        tmp[i] = arr[i - 1];
    }
    arr = tmp;
    delete[] arr;
    ++m_size; 
}

Vector& Vector::operator=(const Vector& other)
{
    if(this != &other)
    {
        int *tmp = this->arr;
        this->clear();
        this->m_capacity = other.m_capacity;
        this->m_size = other.m_size;
        this->arr = tmp;
    }
    return *this;
}

void Vector::display()
{
    for(int i = 0; i < m_size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}