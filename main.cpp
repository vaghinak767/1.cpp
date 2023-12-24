#include "vector.h"

int main()
{
    int n = 0; 
    std::cin >> n;
    Vector arr(n);
    Vector arr_1(n + 1);
    for(int i = 0; i < n; ++i)
    {
        int tmp = 0;
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    for(int i = 0; i < n + 1; ++i)
    {
        int tmp = 0;
        std::cin >> tmp;
        arr_1.push_back(tmp);
    }
    arr.display();
    arr = arr_1;
    arr.display();
    arr_1.display();
}