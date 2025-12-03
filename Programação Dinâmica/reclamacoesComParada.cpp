#include <iostream>
#include <vector>

using namespace std;
int equacao(int d) {
    int r = (200 - d)*(200 - d);
    return r;
}

int reclamacoes(const vector<int>& P, int n) {
    int R[n];R[0] = 0;
    int U[n];U[0] = 0;
    
    for (int i = 1; i < n; i++) {
        int menor = 1000000000; 
        int p_atual = 0;

        for (int j = 0; j < i; j++) {
            int custo = equacao((P[i] - P[j]));
            int r_paradas = R[j] + custo;           
            if(menor > r_paradas){
                menor = r_paradas;
                p_atual = j;
            }
        }
        R[i] = menor;
        U[i] = p_atual;
    }

    cout << "Paradas feitas: ";
    int ultimo = U[0];
    cout << U[0] << " -> ";
    for(int i : U){
        if (i != ultimo){
            cout << i << " -> ";
            ultimo = i;
        }
    }
    cout << n-1 << endl;
    return R[n - 1]; 
}

int main() {
    vector<int> paradas = { 0 , 180, 240, 440, 640};
    int n = paradas.size();
    cout << "Quantidade minima de reclamacoes: " << reclamacoes(paradas, n) << endl;
    return 0;
}