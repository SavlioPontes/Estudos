#include <iostream>
using namespace std;

int P_recursivo(int n){
    if(n <= 4){
        return 0;
    }

    return P_recursivo(n/2) + P_recursivo((n/2) + 1) + P_recursivo((n/2) + 2) + n;
}

int P_dp(int n){
    int dp[n+1];
    for(int i = 0; i <= 4; i++){
        dp[i] = 0;
    }
    if(n <= 4){
        return 0;
    }
    for(int i = 5; i <= n; i++){    
        dp[i] = dp[i/2] + dp[(i/2) + 1] + dp[(i/2) + 2] + i;
    }
    return dp[n];
}

int memo[1000];
int P_memo(int n){
    if(n <= 4){
        memo[n] = 0;
        return memo[n];
    }
    if(memo[n] != 0){
        return memo[n];
    }
    memo[n] = P_memo(n/2) + P_memo((n/2) + 1) + P_memo((n/2) + 2) + n;
    return memo[n];

}

int main(){
    P_recursivo(6);
    P_dp(6);
    P_memo(6);
    //devido às frequentes chamadas no modelo de recursão,ela visivelmente 
    //requer mais tempo as outras funçoes
}
