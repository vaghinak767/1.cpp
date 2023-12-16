#ifndef CLASS_H
#define CLASS_H
#include <string>
#include <iostream>

class Menuitem
{
    private:
        std::string m_name;
        double m_price;
    public:
    Menuitem();
        Menuitem(std::string name, double price)
        {
            m_name = name;
            m_price = price;
        }
        void display();
        std::string get_name();
        int get_price();
};
#endif
