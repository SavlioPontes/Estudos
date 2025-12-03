#include <iostream>
#include <vector>
using namespace std;

int equacao(int d) {
    int r = (200 - d)*(200 - d);
    return r;
}
int memo(const vector<int> P,int k){
    if(k == 0){
        return 0;
    }
    int menor = 1000000000;
    for(int j = 0; j < k; j++){
        int custo = equacao((P[k] - P[j]));
        int r_paradas = memo(P,j) + custo;
        if(menor > r_paradas){
            menor = r_paradas;
        }
    }
    return menor;   
}
int reclamacoes(int n) {
    vector<int> P = { 0 , 180, 240, 440, 640};
    int dp[n];
    for(int i = 0; i < n; i++){
        dp[i] = memo(P,i);
        cout << "dp[" << i << "] = " << dp[i] << endl;
    }
    return dp[n-1];
} 
int main() {
    int n = 5;
    cout << "Quantidade minima de reclamacoes: " << reclamacoes(n) << endl;
    return 0;
}
