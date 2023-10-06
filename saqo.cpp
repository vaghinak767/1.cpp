#include <iostream>
int main(){
int size=0;
bool n = false;
int j = 1;
std::cin>>size;
int target=size;
int* arr = new int [size];
   for(int i=0; i<size; i++){
   std::cin>>arr[i];
   }
   for(j=1; j<=target; j++){
      for(int i=0; i<size; i++){
         if(arr[i]==j){
           n=true;
           }
         }
         if(n==false){
         std::cout<<"Missing number = " <<j<<"\n";
   }
  n=false;
  }
delete []arr;
}
