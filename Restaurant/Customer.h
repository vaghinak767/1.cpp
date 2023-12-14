#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>

class Customer
{
    private:
        std::string m_name;
        std::string m_contanctInfo;
    public:
        Customer(std::string& name, std::string contactInfo)
        {
            m_name = name;
            m_contanctInfo = contactInfo;
        }
        std::string get_name();
        std::string get_info();
};
#endif
