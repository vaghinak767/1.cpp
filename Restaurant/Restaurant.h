#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include <vector>
#include "Menuitem.h"
#include "Order.h"
#include "Customer.h"
class Restaurant
{
    private:
        std::vector<Menuitem> menu;
        std::vector<Order> orderHistory;
    public:
        void add(Menuitem item);
        void display();
        void placeOrder(Order member);
        void display_menu();
};

#endif