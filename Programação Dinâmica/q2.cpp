#include <iostream>
using namespace std;    

int SubSeqCresc_continua(int A[],int n){ // como é continua olha apenas com o antecessor
    int dp[n];
    dp[0] = 1;
    int seq = 1;
    for (int i = 1; i < n; i++){
        if(A[i] > A[i-1]){
            dp[i] = dp[i-1] + 1;
        }else{
            dp[i] = 1;
        }
        seq = max(seq,dp[i]);
    }
    return seq;
}
int SubSeqCresc(int A[],int n){ // tem que olha a interaçãio de cada n com seus anteriores
    int dp[n];
    dp[0] = 1;
    int ans = 1;
    for(int i = 1;i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if(A[i] > A[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

int main(){
    int A[] = {4,10,3,12,1,15};
    int n = 6;
    int r = SubSeqCresc(A,n);
    cout << r;
}