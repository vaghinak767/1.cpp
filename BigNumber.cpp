#include <iostream>
void BigNumberAdd(int* Number1, int* Number2, int* result, int n){
    for(int i=n-1; i>=0; --i){
        result[i+1]+=(Number1[i]+Number2[i]);
        if(result[i+1]>=10){
            result[i+1]=result[i+1]%10;
            ++result[i];
        }
    }
    std::cout<<"number1 + Number2 = ";
    if(result[0]!=0)
        std::cout<<result[0];
    for(int i=1; i<n+1; ++i){
    std::cout<<result[i];
    }
    std::cout<<std::endl;
    for(int i=0; i<n+1; ++i){
        result[i]=0;
    }
} 
void BigNumberSubtraction(int* Number1, int* Number2, int* result, int n){
    for(int i=0; i<n; ++i){
        if(Number1[i]<Number2[i]){
            int a=0, b=Number2[n-1];
            for(int i=n-1; i>=0; --i){
                    a=b;
                    if(i>=1){
                        b=Number2[i-1];
                    }   
                    if(a<Number1[i]){
                        a+=10;
                        --b;
                    }
                    a-=Number1[i];
                    result[i]=a;
                }
            std::cout<<"Number1 - Number2 = -";
            for(int i=0; i<n; ++i){
            std::cout<<result[i];
            }
            std::cout<<std::endl;
            for(int i=0; i<n+1; ++i){
                result[i]=0;
            }
            break;
        }
        else if(Number1[i]<Number2[i]){
            int a=0, b=Number1[n-1];
            for(int i=n-1; i>=0; --i){
                a=b;
                if(i>=1){
                    b=Number1[i-1];
                }
                if(a<Number2[i]){
                    a+=10;
                    --b;
                }
                a-=Number2[i];
                result[i]=a;
            }
            std::cout<<"Number1 - Number2 = ";
                for(int i=0; i<n; ++i){
                    std::cout<<result[i];
                }
            std::cout<<std::endl;
                for(int i=0; i<n+1; ++i){
                    result[i]=0;
                }
                break;
        }
    }
}
int main(){
    int n=0;
    std::cin>>n;
    int* Number1 = new int[n];
    for(int i=0; i<n; ++i){
        std::cin>>Number1[i];
    }
    int* Number2 = new int[n];
    for(int i=0; i<n; ++i){
        std::cin>>Number2[i];
    }
    int* result = new int[n+1];
    for(int i=0; i<n+1; ++i){
        result[i]=0;
    }
    BigNumberSubtraction(Number1, Number2, result, n);
    BigNumberAdd(Number1, Number2, result, n);
    delete[] Number1;
    delete[] Number2;
    delete[] result;
    return 0;
}
