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
    cout << "Maiores subsequencias contigtuas : ";
    for(int i : P){
        cout << i << " ";
    }
    cout << endl;
    return maior;
}

int main(){
    vector <int> sequencia = { 5, 15, -30, 10, -5, 40, 10};
    int n = sequencia.size();
    cout << "Sequencia: ";
    for(int i : sequencia){
        cout << i << " ";
    }
    cout << endl;
    cout << "Maior soma: " << subsoma(sequencia,n);
    }