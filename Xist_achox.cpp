#include <iostream>

bool solution(int *arr, int size){
    int index = 0;
    for(int i = 0; i < size - 1; ++i){
        for(int j = i + 1; j < size; ++j){
            if(arr[i] >= arr[j]){
                index = i;
            }
        }
    }
    for(int i = 0; i < size - 1; ++i){
        if(i == index){
            continue;
        }
        int count = 0;
        for(int j = i + 1; j < size; ++j){
            if(j == index){
                continue;
            }
            if(arr[i] >= arr[j]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n = 0;
    std::cin >> n;
    int *arr = new int[n];
    for( int i = 0; i < n; ++i){
        std::cin >> arr[i];
    }
    std::cout << solution(arr, n);
}
