#include <iostream>
int fac(int* cach, int n){
    if(n<1){
        return 1;
    }
    if(cach[n]){
        return cach[n];
    };
    return cach[n]=n*fac(cach, n-1);
}
int main(){
    int n;
    std::cin>>n;
    while(n<1){
    std::cerr<<"Warning! It's a negativ number, please enter positiv number";
    std::cin>>n;
    }
    int* cach=new int [n+1]{0};
    std::cout<<"cach["<<n<<"]="<<fac(cach, n)<<std::endl;
    std::cout<<"cach=";
    for(int i=0; i<n; ++i){
        std::cout<<cach[i];
        if(i<n-1)
        std::cout<<", ";
    }
    std::cout<<std::endl;
    delete[] cach;
}
