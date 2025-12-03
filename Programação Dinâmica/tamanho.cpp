#include <iostream>
#include <vector>
using namespace std;

int lucro(const vector <int> P, int n){
   vector <int> T(n);
   T[0] = P[0];
   int max_lucro =T[0];
   for(int i = 1; i <= n-1; i++){// vai pegar o melhor lucro de cada tamanho i
      T[i] = P[i];
      int maior = T[i];
      for(int j = 1; j < i; j++){
         int t_atual = T[i-j] + T[j-1];
         if(maior < t_atual){
            maior = t_atual;
         }
      }
      T[i] = maior;
      if(max_lucro < T[i]){
         max_lucro = T[i];
      }
   }
   return max_lucro;
}

int main() {

   vector <int> P = {1, 5, 8, 9, 10, 17, 17, 20};
   int T = lucro(P, 8);
   cout << "Lucro maximo: " << T << endl;

}
