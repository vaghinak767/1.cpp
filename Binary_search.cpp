#include <iostream>

int search (int *arr, int size, int target ){
    int left = 0;
    int right = size - 1;
    while(right >= left){
        int mid = left + (right - left) / 2;
        if(target == arr[mid]){
            return mid;
        }
        if(target > arr[mid]){
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return -1; 
}

int main(){
    int n = 0;
    int target = 0;
    std::cin >> n >> target;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i){
        std::cin >> arr[i];
    }
    std::cout << search(arr, n, target );
    delete[]arr;
}
