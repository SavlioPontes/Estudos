#include <iostream>
#include <string>
using namespace std;

int substring(string x,string y){   
    int n = x.length();
    int m = y.length();
    int dp[n][m];
    int ans = 0;
    for(int i = 0; i < n;i++){
        for (int j = 0; j < m; j++){
            if(x[i] == y[j]){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = dp[i-1][j-1] + 1;
                }   
            }else{
                dp[i][j] = 0;
            }
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}


int main(){
    string a = "programa";
    string b = "programacao";
    cout <<  substring(a,b);
}