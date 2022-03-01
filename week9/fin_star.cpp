#include<bits/stdc++.h>
using namespace std;
int A[100001][3];
int dp[100001][3];
int n;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i][1] >> A[i][2];
        if(i==0){
            dp[i][0] = 0;
            dp[i][1] = A[i][1];
            dp[i][2] = A[i][2];
        }
        else{
            dp[i][0] = max(max(dp[i-1][1],dp[i-1][2]),dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0],dp[i-1][2])+ A[i][1];
            dp[i][2] = max(dp[i-1][0],dp[i-1][1])+ A[i][2];
        }
    }
    cout << max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);

}