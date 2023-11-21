#include <iostream>

int index1(const char *arr)
{
    int size = 0;
    while (arr[size])
    {
        ++size;
    }
    int index = 0;
    int max = 0;
    for (int i = 0; i < size;)
    {
        int count = 0;
        int j = i;
        while ((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))
        {
            ++count;
            ++i;
        }
        ++i;
        if (count > max)
        {
            index = j;
            max = count;
        }
    }
    return index;
}

int main()
{
    int n = 0;
    std::cin >> n;
    char *arr = new char[n + 1];
    std::cin.get();
    std::cin.getline(arr, n);
    const char *ptr = const_cast<const char *>(arr);
    int index = index1(arr);
    while ((arr[index] >= 'A' && arr[index] <= 'Z') || (arr[index] >= 'a' && arr[index] <= 'z'))
    {
        std::cout << arr[index];
        ++index;
    }
    std::cout << std::endl;
    delete[] arr;
}
