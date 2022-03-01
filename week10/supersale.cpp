#include<bits/stdc++.h>
using namespace std;
int p[1001],w[1001],dp[31];
int W = 30;
int n;
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> p[i] >> w[i];
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=W;j>=w[i];j--){
                dp[j] = max(dp[j],dp[j-w[i]] + p[i]);
            }
        }
        int g,mw,ans=0; cin >> g;
        for(int i=0;i<g;i++){
            cin >> mw;
            ans+=dp[mw];
        }
        cout << ans << "\n";
    }
}