#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[100001][209];
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        int st = 101 - k;
        int en = 101 + k;
        for(int i=0;i<=n;i++){
            for(int j=st-1;j<=en+1;j++){
                dp[i][j] = 1e9;
            }
        }
        dp[0][101] = 0;
        for(int i=1;i<=n;i++){
            int xx,yy; cin >> xx >> yy;
            for(int j=st;j<=en;j++){
                dp[i][j] = min(dp[i-1][j-1]+xx,dp[i-1][j+1]+yy) ;
            }
        }
        int ans = 1e9;
        for(int j=st;j<=en;j++){
            ans = min(ans,dp[n][j]);
        }
        cout << ans << "\n";
    }
    return 0;
}