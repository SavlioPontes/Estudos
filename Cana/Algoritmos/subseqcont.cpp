#include <iostream>
#include <vector>

using namespace std;

int subsoma(vector <int> S,int n){
    vector <int> P(n);
    P[0] = S[0];
    for(int i = 1; i < n; i++){
        P[i] = max(S[i], S[i]+P[i-1]);
    }
    int maior = P[0];
    for(int i = 1; i < n; i++){
        if(maior < P[i]){
            maior = P[i];
        }
    }
    return maior;
}

int main(){
    vector <int> sequencia = { 5, 15, -30, 10, -5, 40, 10};
    int n = sequencia.size();
    cout << subsoma(sequencia,n);
    }