#include "Restaurant.h"

int main()
{
    Restaurant Art;
    int n = 0;
    std::cin >> n;
    std::vector<Customer> cust;
    std::vector<Menuitem> menu;
    std::cout << "For adding an item in menu press 1: " << std::endl;
    std::cout << "For adding customer press 2:" << std::endl;
    std::cout << "For ordering press 3: " << std::endl;
    for(;std::cin >> n;){
        // while(n < 1 || n > 3)
        // {
        //     std::cout << "For adding an item in menu press 1: " << std::endl;
        //     std::cout << "For ordering press 2: " << std::endl;    
        //     std::cin >> n;    
        // }
        if ( n == 1)
        {
            int j = 0;
            std::cout << "For breaking pree 'k':" << std::endl;
            for(std::string item; std::cin >> item;)
            {
                if(item == "q")
                break;
                double price;
                std::cin >> price;
                menu[j] = Menuitem(item, price);
                ++j;
            }
        }
        if (n == 2)
        {
            std::cout << "Enter customers info: " << std::endl;
            int i = 0;
            for(std::string name; std::cin >> name;)
            {
                if(name == "q")
                break;
                std::string info;
                std::cin >> info;
                cust[i] = Customer(name, info);
                ++i;
            }
        } 
        if(n == 3)
        {
            std::cout << "Enter the items of order:" << std::endl;
            for(std::string item; std::cin >> item;)
            {
                if(item == "q")
                {
                    break;
                }
                add(item)
            }
        }
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