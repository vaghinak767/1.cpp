void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// Merge Sort---------------------------------------------
void merge(int *arr, int left, int right, int mid)
{
    int s1 = mid - left + 1;
    int s2 = right - mid;
    int *arr1 = new int[s1];
    int *arr2 = new int[s2];
    for(int i = 0; i < s1; ++i)
    {
        arr1[i] = arr[left + i];
    }
    for(int i = 0; i < s2; ++i)
    {
        arr2[i] = arr[mid + i + 1];
    }
    int f1 = 0, f2 = 0, j = left; 
    while(f1 < s1 && f2 < s2)
    {
        if(arr1[f1] < arr2[f2])
        {
            arr[j] = arr1[f1];
            ++f1;
        }
        else
        {
            arr[j] = arr2[f2];
            ++f2;
        }
        ++j;
    }
    while(f1 < s1)
    {
        arr[j] = arr1[f1];
        ++f1;
        ++j;
    }
    while(f2 < s2)
    {
        arr[j] = arr2[f2];
        ++f2;
        ++j;
    }
    delete[]arr1;
    delete[]arr2;
}
void MergeSort(int *arr, int b, int e)
{
    if(b >= e)
    {
        return;
    }
    int mid = b + (e - b) / 2;
    MergeSort(arr, b, mid);
    MergeSort(arr, mid + 1, e);
    merge(arr, b, e, mid);
}
//Merge Sort----------------------------------------
//Bubble Sort---------------------------------------

void BubbleSort(int *arr, int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        bool check = false;
        for(int j = i; j < n - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
        if(check)
        {
            break;
        }
    }
}

//Selection Sort-------------------------------------

void SelectionSort(int* arr, int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        int min = i;
        bool check = false;
        for(int j = i + 1; j < n; ++j)
        {
            if(arr[min] > arr[j])
            {
                min = j;
                check = true;
            }
        }
        if(check)
        {
            swap(arr[min], arr[i]);
        }
    }
}

//Insertion Sort----------------------------------

void InsertionSort(int* arr, int n)
{
    for(int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

#include <iostream>
int main()
{
    int n = 0;
    std::cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    InsertionSort(arr, n);
    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
}

