#include <iostream>
#include <vector>
using namespace std;

// Função que faz a intercalação (merge) de duas metades ordenadas
void merge(vector<int>& A, int i, int f, vector<int>& aux){
    int meio = (i + f) / 2;       // calcula o meio da sublista
    int left = i;                 // índice inicial da metade esquerda
    int right = meio + 1;         // índice inicial da metade direita
    int k = i;                     // índice para percorrer o vetor auxiliar

    // enquanto houver elementos nas duas metades
    while (left <= meio && right <= f) {
        if (A[left] <= A[right]) aux[k++] = A[left++];  // pega o menor da esquerda ou direita
        else aux[k++] = A[right++];
    }

    // copia os elementos restantes da metade esquerda, se houver
    while (left <= meio) aux[k++] = A[left++];

    // copia os elementos restantes da metade direita, se houver
    while (right <= f) aux[k++] = A[right++];

    // copia de volta para o vetor original a parte já ordenada
    for (int t = i; t <= f; t++)
        A[t] = aux[t];
}

// Função recursiva do merge sort
void mergeSort(vector<int>& A, int i, int f, vector<int>& aux){
    if (i < f){                    // condição de parada: sublista com 1 elemento
        int meio = (i + f) / 2;    // calcula o meio da sublista
        mergeSort(A, i, meio, aux);      // ordena a primeira metade
        mergeSort(A, meio + 1, f, aux);  // ordena a segunda metade
        merge(A, i, f, aux);             // intercala as duas metades já ordenadas
    }
}

int main(){
    vector<int> A = {7,5,10,4,8,2,6,1,9,3};  // vetor original
    vector<int> aux(A.size());               // vetor auxiliar usado na intercalação

    mergeSort(A, 0, A.size() - 1, aux);     // chama a função merge sort

    // imprime o vetor já ordenado
    for(int i : A){
        cout << i << " ";
    }
}
