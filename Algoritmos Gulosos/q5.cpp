#include <iostream>
using namespace std;

struct Atividade {
    int inicio;
    int fim;
};

void insertion(Atividade A[],int n){
    for (int i = 1; i < n; i++){
        int k = i;
        int j = i-1;
        while (j >= 0 && A[k].inicio < A[j].inicio)
        {
            swap(A[k],A[j]);
            k--;
            j--;
        }
    }
}

int prazos(Atividade A[],int n){
    insertion(A,n);
    Atividade atual = A[n-1];
    int q = 1;
    for (int i = n-2; i >= 0; i--){
        int t = atual.inicio;
        if(A[i].fim <= t){
            atual = A[i];
            q++;
        }
    }
    return q;
    
}

int main() {
    Atividade A[] = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };

    int n = 6;

    cout << prazos(A, n) << endl;
}
