#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Caixa {
    int peso;
    int objetos;
};

// critério guloso: p / k crescente
bool compara(Caixa a, Caixa b) {
    return (double)a.peso / a.objetos < (double)b.peso / b.objetos;
}

int main() {
    vector<Caixa> caixas = {
        {10, 1},
        {2, 5},
        {6, 2},
        {4, 3}
    };

    // ordena as caixas
    sort(caixas.begin(), caixas.end(), compara);

    // calcula o esforço
    int peso_acima = 0;
    int esforco = 0;

    for (int i = 0; i < caixas.size(); i++) {
        esforco += caixas[i].objetos * peso_acima;
        peso_acima += caixas[i].peso;
    }

    cout << "Esforco total: " << esforco << endl;

    return 0;
}
