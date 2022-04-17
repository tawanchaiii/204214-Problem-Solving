#include<bits/stdc++.h>
using namespace std;
int n,k;
int A[5001];
int dp[5001][5001];
int solve(int p,int w){
    if(p==0) // boundary condition
        return 0; 
    if(dp[p][w] != -1)
        return dp[p][w];
    if(w >= A[p])
        return dp[p][w] = min(solve(p-1,k) + A[p] , solve(p-1,w-A[p]));
    else
        return dp[p][w] = solve(p-1,k) + A[p];
}
int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> A[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << solve(n,k);
}