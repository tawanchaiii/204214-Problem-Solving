#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int A[205][205];
int dp[205][205][205];
int  solve(int x,int y,int k){
    if(x==n+1 || y == 0 || y == m+1)
        return 0;
    if(dp[x][y][k] != 0)
        return dp[x][y][k];
    if(k>0)
        return dp[x][y][k] = max(solve(x+1,y-1,k-1) + A[x][y] , max(solve(x+1,y,k)+A[x][y] , solve(x+1,y+1,k-1)+A[x][y]));
    return dp[x][y][k] = solve(x+1,y,k) + A[x][y]; 
}
int main(){
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> A[i][j];
        }
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        ans = max(solve(1,i,k),ans);
    }
    cout << ans;
}