#include <iostream>
#include <algorithm>
using namespace std; 

int devolucao(int n,int L[]){
    for (int i = 1; i < n; i++){
        int k = i;
        int j = i-1;
        while (j >= 0 && L[k] < L[j]){
            swap(L[k],L[j]);
            k = j;
            j--;
        }
    }

    int atraso = 0;
    int multa = 0;
    for(int i = 0; i < n; i++){
       atraso += L[i];
       multa += atraso;
    }
    for(int i = 0; i < n; i++){
        cout << L[i] << ",";
    }
    cout << endl;

    return multa;
}

int main(){
    int n = 5;
    int L[n] = {3,5,6,2,7};
    cout << devolucao(n,L);
}
