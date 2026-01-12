#include <iostream>
#include <algorithm>
using namespace std; 

int times(int n,int M[],int H[]){
    int I[n];
    int maximo = 0;
    int minimo = 10000;
    for (int i = 0; i < n; i++){
        I[i] = (M[i] + H[n-1-i])/2;
        maximo = max(maximo,I[i]);
        minimo = min(minimo,I[i]);
    }    
    return (maximo - minimo);
}

int main(){
    int n = 5;
    int M[n] = {3,5,6,9,10};
    int H[n] = {1,6,8,10,15};
    cout << times(n,M,H);
}
