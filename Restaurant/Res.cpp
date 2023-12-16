#include "Menuitem.h"
#include "Order.h"
#include "Customer.h"
#include "Restaurant.h"

void Menuitem::display()
{
    std::cout << m_name << std::endl;
    std::cout << m_price;
}

void Order::add(Menuitem item)
{
    items.push_back(item);
    m_totalPrice += item.get_price();
}

void Oreder::set(std::string& name)
{
    m_customerName = name;
}
void Order::display()
{
    //std::cout << "Custumer name: " << m_customerName << std::endl;
    std::cout << std::endl;
    for(Menuitem item : items)
    {
        std::cout << item.get_name() << "  " << item.get_price() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "The total price: " << m_totalPrice << std::endl;
    std::cout << std::endl << "-----------------------------------------" << std::endl;
}

std::string Customer::get_name()
{
    return m_name;
}

std::string Customer::get_info()
{
    return m_contanctInfo;
}

void Restaurant::add(Menuitem item)
{
    menu.push_back(item);
}

void Restaurant::placeOrder(Order member)
{
    orderHistory.push_back(member);
}

void Restaurant::display()
{
    for(Order order : orderHistory)
    {
        order.display();
    }
}

void Restaurant::display_menu()
{
    std::cout << "  Item   " << "Price" << std::endl; 
    int i = 1; 
    for(Menuitem item : menu)
    {
        std::cout << i << ". ";
        ++i;
        std::cout << item.get_name() << "   " << item.get_price() << std::endl;
    }
    std::cout << std::endl;
}