#include <iostream>
int k = 0;
void Big_number_division(int *Number1, int *Number2, int *result, int n)
{
    int pad = 0, count = 9;
    for (int i = 0; i < n; ++i)
    {
        do
        {
            int z = 0;
            if (Number2[i] == 0 && Number1[i] == 0)
            {
                continue;
            }
            while (Number2[i + pad] == 0)
            {
                ++pad;
            }
            int count = 0, tiv = Number1[i];
            if (i + pad == n)
            {
                break;
            }
            while (Number1[i] >= Number2[i + pad] && Number1[i] != 0 && Number2[i + pad])
            {
            }
        } while (0); //------------------------------------------
    }
}
void Big_number_add(int *Number1, int *Number2, int *result, int n)
{
    for (int i = n - 1; i >= 0; --i)
    {
        result[i + 1] += (Number1[i] + Number2[i]);
        if (result[i + 1] >= 10)
        {
            result[i + 1] = result[i + 1] % 10;
            ++result[i];
        }
    }
    std::cout << "Number1 + Number2 = ";
    while(result[k] == 0)
    {
        ++k;
    }
    for (int i = 1; i < n + 1; ++i)
    {
        std::cout << result[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < n + 1; ++i)
    {
        result[i] = 0;
    }
    k = 0;
}
void Big_number_multipy(int *Number1, int *Number2, int *result, int n)
{
    int a = 0;
    int m = 2 * n - 1;
    for (int c = n - 1; c >= 0; --c)
    {
        for (int j = m, l = n - 1; j > c && l >= 0; --j, --l)
        {
            for (int i = 0; i < Number2[c]; ++i)
            {
                result[j] += Number1[l];
            }
            if (result[j] >= 0)
            {
                result[j - 1] += (result[j] / 10);
                a = result[j];
                result[j] = 0;
                result[j] = (a % 10);
            }
        }
        --m;
    }
    while(result[k] == 0)
    {
        ++k;
    }
    std::cout << "Number1 * Number2 = ";
    for (int i = k; i < 2 * n; ++i)
    {
        std::cout << result[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < n + 1; ++i)
    {
        result[i] = 0;
    }
    k = 0;
}
void Big_number_subtraction(int *Number1, int *Number2, int *result, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (Number1[i] < Number2[i])
        {
            int a = 0, b = Number2[n - 1];
            for (int i = n - 1; i >= 0; --i)
            {
                a = b;
                if (i >= 1)
                {
                    b = Number2[i - 1];
                }
                if (a < Number1[i])
                {
                    a += 10;
                    --b;
                }
                a -= Number1[i];
                result[i] = a;
            }
            std::cout << "Number1 - Number2 = -";
            while(result[k] == 0)
            {
                ++k;
            }
            for (int i = k; i < n; ++i)
            {
                std::cout << result[i];
            }
            std::cout << std::endl;
            for (int i = 0; i < n + 1; ++i)
            {
                result[i] = 0;
            }
            break;
        }
        else if (Number1[i] > Number2[i])
        {
            int a = 0, b = Number1[n - 1];
            for (int i = n - 1; i >= 0; --i)
            {
                a = b;
                if (i >= 1)
                {
                    b = Number1[i - 1];
                }
                if (a < Number2[i])
                {
                    a += 10;
                    --b;
                }
                a -= Number2[i];
                result[i] = a;
            }
            while(result[k] == 0 && k <= 2 * n)
            {
                    ++k;
            }
            std::cout << "Number1 - Number2 = ";
            for (int i = k; i < n; ++i)
            {
                std::cout << result[i];
            }
            std::cout << std::endl;
            for (int i = 0; i < n; ++i)
            {
                result[i] = 0;
            }
            break;
        }
        else{
            std::cout << "Number1 - Number2 = "<< "0" << std::endl;
        }
    }
    k = 0;
}
int main()
{
    int n = 0;
    std::cout << "Please enter the count of digits ";
    std::cin >> n;
    int *Number1 = new int[n];
    std::cout << "Please enter the digits of first number ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> Number1[i];
    }
    std::cout << "Please enter the digits of second number ";
    int *Number2 = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> Number2[i];
    }
    int *result = new int[2 * n];
    for (int i = 0; i < 2 * n; ++i)
    {
        result[i] = 0;
    }
    Big_number_subtraction(Number1, Number2, result, n);
    Big_number_add(Number1, Number2, result, n);
    Big_number_multipy(Number1, Number2, result, n);
    delete[] Number1;
    delete[] Number2;
    delete[] result;
    return 0;
}
