#ifndef ORDER_H
#define ORDER_H
#include"Menuitem.h"
#include <iostream>
#include <vector>
class Order
{
    private:
        std::string m_customerName;
        std::vector<Menuitem> items;
        double m_totalPrice;
    public:
        Order(std::string name)
        {
            m_customerName = name;
        }
        void set(std::string& name);
        void add(Menuitem item);
        void display();
};
#endif