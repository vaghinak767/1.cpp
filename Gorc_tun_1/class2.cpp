#include "class2.h"

void BankAccount::setter()
{
    std::cout << "Enter the number of account: ";
    std::cin >> account_number;
    std::cout << "Enter the name of account holder: ";
    std::cin >> account_holder;
}

void BankAccount::display()
{
    std::cout << "The number of account: ";
    std::cout << account_number << std::endl;
    std::cout << "The name of account holder: ";
    std::cout << account_holder << std::endl;
    std::cout << "The balance of account: ";
    std::cout << balance << std::endl;
}

void BankAccount::deposit(double amount)
{
    balance += amount;
}

void BankAccount::withdraw(double amount)
{
    if (amount > balance)
    {
        throw std::invalid_argument(" ");
    }
    balance -= amount;
}

int main()
{
    BankAccount info;
    info.setter();
    std::cout << "For deposition press 1 " << std::endl;
    std::cout << "For withdrawing press 2 " << std::endl;
    std::cout << "To exit press q" << std::endl;
    short key = 0;
    double amount = 0.0;
    for (; std::cin >> key;)
    {
        if (key == 1)
        {
            std::cout << "Enter the amount of money that you want to deposit: ";
            std::cin >> amount;
            info.deposit(amount);
        }
        else if (key == 2)
        {
            std::cout << "Enter the amount of money that you want to whitdraw: ";
            std::cin >> amount;
            info.withdraw(amount);
        }
    }
    info.display();
}