#include <iostream>
int main(){
    int size=0, target=0, left = 0;
    std::cin>>size>>target;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        std::cin>>arr[i];
    }
    int right = size-1;
    for (int i = 0; i < size; i++)
    {int mid = (right + left)/2;
        if(arr[mid]>target){
            left--;
        }
        else
        if(arr[mid]<target){
            right++;
        }
        else{
            std::cout<<mid;
            return 0;
        }
    }
    std::cout<<"There is not target";
    delete []arr;
}