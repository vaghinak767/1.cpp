#include <iostream>
int main(){
    int size=0, target=0, left = 0;
    std::cout<<"Input size of array ";
    std::cin>>size;
    std::cout<<"Input your target ";
    std::cin>>target;
    int* arr = new int[size];
    std::cout<<"Input array's elements ";
    for (int i = 0; i < size; i++)
    {
        std::cin>>arr[i];
    }
    int right = size-1;
    int mid;
    for (int i = 0; i < size; i++)
    {
        mid = (right + left)/2;
        if(arr[mid]>target){
            left--;
        }
        else
        if(arr[mid]<target){
            right++;
        }
        else{
            std::cout<<"Your target index is = "<<mid;
            return 0;
        }
    }
    std::cout<<"There is not target";
    delete []arr;
}
