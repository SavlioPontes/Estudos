#include <iostream>
using namespace std;

int pontes(int n,int A[],int B[],int C[][]){
    int dp[n];
    dp[0] = C[0][0];
    dp[1] = dp[0] + C[1][1];
    for (int i = 2; i < n; i++){
        dp[i] = dp[i-1] + C[i][i];
        if(C[i-1][i-1] > (C[i-1][i] + C[i-2][i-1])){
            dp[i] = dp[i-2] + (C[i-1][i] + C[i-2][i-1]) + C[i][i];
        } 
    }
    return dp[n];
}

int main(){
    int n = 5;
    int A[5]
}