#include <iostream>

struct Vector{
    int size;
    int capacity;
    int* arr;
};


void realloc_1(Vector& v){
    if(v.capacity==0){
        v.capacity=1;
    }
    int* arr_1=new int[2*v.capacity];
    for(int i=0; i<v.capacity; ++i){
        arr_1[i]=v.arr[i];
    }
    v.capacity*=2;
    delete[]v.arr;
    v.arr=arr_1;
}


void pushback(Vector& v, int n){
    if(v.capacity==0){
        int a=8;
        realloc_1(v);
    }
    if(v.size==v.capacity){
        realloc_1(v);
    }
    v.arr[v.size]=n;
    ++v.size;
}

void popback(Vector& v){
    if(v.size==0){
        std::cout<<"There is no block of vector:";
        return;
    }
    v.arr[v.size]=0;
    --v.size;
}

int main(){
    Vector v;
    // std::cin>>v.capacity;
    // v.arr=new int[v.capacity];
    // v.size=0;
    // for(int i=0; i<v.capacity; ++i){
    //     int n=0;
    //     std::cin>>n;
    //     pushback(v, n);
    // }
    int a=0;
    std::cout<<"For working with vector press 1:";
    std::cout<<"For breaking working with vector press 0:";
    int n=0;
    while(std::cin>>a){
    while(a){
        int k=0;
        std::cout<<"For Push press 1:"<<std::endl<<"For Pop press 2:";
        std::cin>>k;
        switch(k){
            case 1: 
                std::cin>>n;
                pushback(v, 10);
                break;
            case 2:
                popback(v);
                break;
            default:
            continue;
        }
    }
    }
}
