#include <iostream>

union Tiv{
    int a;
    double b;
};
enum Signal{
ONE = 1, TWO
};

Tiv proc(Tiv c, Signal l){
    switch(l){
        case ONE: {
            c.a*=c.a;
            break;
        }
        case TWO: {
            c.b*=2;
            break;
        }   
    }
    return c;
}

int main(){
    Tiv c;
    int tmp = 0;
    std::cout<<"For square press 1: "<<std::endl<<"For double press 2:"<<std::endl;
    std::cin>>tmp;
    Signal l = (Signal)tmp;
    if(tmp == 1){
        std::cin>>c.a;
        Tiv result;
        result = proc(c, l);
        std::cout<<result.a<<std::endl;
    }
    if(tmp == 2){
        std::cin>>c.b;
        Tiv result;
        result = proc(c, l);
        std::cout<<result.b<<std::endl;
    }
    return 0; 
}
