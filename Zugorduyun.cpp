#include <iostream>

int c(int n, int k)
{
    if ((k == n) || (k == 0))
        return 1;
    else if (k > n)
        return 0;
    else
        return c(n - 1, k - 1) + c(n - 1, k);
}

int main()
{
    for (int n, k; std::cin >> n >> k;)
        std::cout << c(n, k) << std::endl;
}
