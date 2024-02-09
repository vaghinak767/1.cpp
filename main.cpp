#include "double_linked_list.h"

int main()
{
    List ob;
    ob.push_front(10);
    ob.push_back(7);
    ob.push_front(6);
    ob.push_front(3);
    ob.push_front(8);
    ob.erase(4, 11);
    ob.display();
    ob.display_dec();
    ob.display_inc();
}
