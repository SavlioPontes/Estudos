#include <iostream>
using namespace std;

bool subsoma(int t,int n,int A[]){
    bool dp[n+1][t+1];

    for (int k = 0; k <= n; k++){
        dp[k][0] = true;
    }
    
    dp[0][0] = true;
    for (int s = 1; s < t; s++){
       dp[0][s] = false;
    }

    for (int k = 1; k <= n; k++){
        for (int s = 1; s <= t; s++){
            dp[k][s] = dp[k-1][s];
            if (s >= A[k]){
                dp[k][s] = dp[k][s] || dp[k-1][s-A[k-1]];
            }
            
        }
    }
    return dp[n][t];
}

int main(){
   int A[] = {3, 34, 4, 12, 5, 2};
    int n = 6;
    int T = 9;
    cout << subsoma(T,n,A);
}