#include <iostream>
#include <vector>

using namespace std;
int equacao(int d) {
    int r = (200 - d)*(200 - d);
    return r;
}

int reclamacoes(const vector<int>& P, int n) {
    vector<int> R(n); 
    R[0] = 0; 
    for (int i = 1; i < n; i++) {
        R[i] = 1000000000; 
        
        for (int j = 0; j < i; j++) {
            int custo = equacao((P[i] - P[j]));
            int r_paradas = R[j] + custo;           
            R[i] = min(R[i], r_paradas);
        }
    }
    return R[n - 1]; 
}

int main() {
    vector<int> paradas = { 0 , 180, 240, 440, 640};
    int n = paradas.size();
    cout << reclamacoes(paradas, n) << endl;
    return 0;
}
