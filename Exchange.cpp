#include <iostream>

enum Valuta{
    AMD = 1, USD, RUR
};
long Exchange(Valuta from, Valuta to, long amount){
    switch (from){
        case AMD: {
            switch (to){
                case AMD: {
                    std::cout<<"The amount of money from AMD to AMD is ";
                    return amount;
                }
                case RUR: {
                    std::cout<<"The amount of money from AMD to RUR is ";
                    return amount/4;
                }
                case USD: {
                    std::cout<<"The amount of money from AMD to USD is ";
                    return amount/395;
                }
    }
        }
        case USD: {
            switch (to){
                case AMD: {
                    std::cout<<"The amount of money from USD to AMD is ";
                    return amount*395;
                    }
                case RUR: {
                    std::cout<<"The amount of money from USD to RUR is ";
                    return amount*41;
                    }
                case USD: {
                    std::cout<<"The amount of money from USD to USD is ";
                    return amount;
                }
            }
        }
        case RUR:{
            switch (to){
                case AMD: {
                    std::cout<<"The amount of money from RUR to AMD is ";
                    return amount*4;
                }
                case RUR: {
                    std::cout<<"The amount of money from RUR to RUR is ";
                    return amount;
                }
                case USD: {
                    std::cout<<"The amount of money from RUR to USD is ";
                    return amount/41;
                }
            }
        }
    }
return 0;
}

int main(){
    long amount = 0;
    std::cout<<"Enter the \"from\" Valuta"<<std::endl<<"For AMD enter 1"<<std::endl<<"For USD enter 2"<<std::endl<<"For RUR enter 3"<<std::endl;
    int value = 0;
    std::cin>>value;
    Valuta from = (Valuta)value;
    std::cout<<"Enter the \"to\" Valuta"<<std::endl<<"For AMD enter 1"<<std::endl<<"For USD enter 2"<<std::endl<<"For RUR enter 3"<<std::endl;
    int valueto = 0;
    std::cin>>valueto;
    Valuta to = (Valuta)valueto;
    std::cout<<"Enter the amount of money"<<std::endl;
    std::cin>>amount;
    std::cout<<Exchange(from, to, amount)<<std::endl;
    return 0;
}
