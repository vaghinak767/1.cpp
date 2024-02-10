#include "double_linked_list.h"

int main()
{
    List ob;
    ob.push_back(1);
    ob.push_back(3);
    ob.push_back(5);
    ob.push_back(7);
    ob.push_back(10);
    ob.push_back(11);
    ob.push_back(12);
    ob.insert(8, 2);
    // ob.erase(3);
    // ob.erase(4, 8);
    // List obj = List();
    // obj = ob;
    // std::cout << obj.size() << std::endl << ob.size() <<  std::endl;
    ob.display();
    ob.display_dec();
    ob.display_inc();
}
