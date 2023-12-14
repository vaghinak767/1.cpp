#include "Restaurant.h"

int main()
{
    Restaurant Art;
    int n = 0;
    std::cin >> n;
    std::vector<Menuitem> menu;
    std::cout << "Enetr the items of menu: " << std::endl;
    for(Menuitem tmp : menu)
    {
        std::string item;
        double price;
        std::cin >> item >> price;
        tmp = Menuitem(item, price);
    }
    std::vector<Customer> cust;
    std::cout << "Enter customers info: " << std::endl;
    for(Customer tmp : cust)
    {
        std::string name;
        std::string info;
        std::cin >> name >> info;
        tmp = Customer(name, info);
        
    }
    Art.display_menu();
    zakaz2.add(fri);
    zakaz2.add(hac);
    zakaz.add(fri);
    zakaz.add(hac);
    zakaz.add(jur);
    std::cout << "Orders" << std::endl << std::endl;
    std::cout << Artyom.get_name() << " . " << Artyom.get_info() << std::endl;
    Art.placeOrder(zakaz);
    Art.placeOrder(zakaz2);
    Art.display();
}