#include <iostream>
#include <string>

class BankAccount
{
    int account_number;
    std::string account_holder;
    double balance;
public:
    void display();
    void deposit(double amount);
    void withdraw(double amount);
    void setter();
};