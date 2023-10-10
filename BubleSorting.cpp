#include <iostream>
void Sorting(int* arr, int size){
    for(int i=0; i<size-1; ++i){
        for(int j=i+1; j<size; ++j){
            if(arr[i]>arr[j]){
                int c=arr[i];
                arr[i]=arr[j];
                arr[j]=c;
            }
        }
    }
}
int main(){
    int size=0;
    std::cin>>size;
    int* arr = new int[size];
    for(int i=0; i<size; ++i){
        std::cin>>arr[i];
    }
    Sorting(arr, size);
    for(int i=0; i<size; ++i){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
