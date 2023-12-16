#include <iostream>
int solution(int **, int, int);
int sol(int **, int, int);
int main()
{

    int n = 0;
    int m = 0;
    std::cout << "Please enter the matrix dimensions" << std::endl
              << "The size of rows: ";
    std::cin >> n;
    std::cout << "The size of columns: ";
    std::cin >> m;
    int **arr = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = new int[m];
    }
    std::cout << "Please enter the members of matrix" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> arr[i][j];
        }
    }
    std::cout << "For first solution press 1:" << std::endl;
    std::cout << "For second solution press 2:" << std::endl;
    int key = 0;
    while (key != 1 && key != 2)
    {
        std::cin >> key;
    }
    if (key == 1)
    {
        std::cout << solution(arr, n, m) << std::endl;
    }
    if (key == 2)
    {
        std::cout << sol(arr, n, m) << std::endl;
    }
    for (int i = 0; i < n; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
int solution(int **matrix, int size, int size1)
{
    int sum = 0;
    for (int j = 0; j < size1; ++j)
    {
        int i = 0;
        while ((i < size) && (matrix[i][j] != 0))
        {
            sum += matrix[i][j];
            ++i;
        }
    }
    return sum;
}

int sol(int **arr, int size, int size1)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size1; ++j)
        {
            if (i != (size - 1) && arr[i][j] == 0)
            {
                arr[i + 1][j] = 0;
            }
            sum += arr[i][j];
        }
    }
    return sum;
}
