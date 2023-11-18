#include <iostream>
int solution(int **matrix, int size, int size1 ) {
    int sum = 0;
    int min = 0;
    for(int j = 0; j < size1; ++j){
        int i = 0; 
        if(matrix[i][j] != 0){
            while(i<size){
                while(matrix[i][j]!=0){
                sum += matrix[i][j];
                }
                ++i;
            }
        }
    }
    return sum;
}
int main(){
    int n = 0, m = 0;
    std::cin >> n >> m;
    int **arr = new int*[n];
    for(int i = 0; i < n; ++i){
        *arr = new int[m];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            std::cin >> arr[i][j];
        }
    }
    std::cout << solution(arr, n, m);
    for(int i = 0; i < n; ++i){
        delete[]arr[m];
    }
    delete[]arr;
}
