#include <bits/stdc++.h>
using namespace std;
string str;
int dp[1001][26][26];
int n,ans;
int dist(int x,int y){
    return min(abs(x-y),26-abs(x-y));
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> str;
        n = str.length();
        for(int i=0;i<n;i++){
            for(int x=0;x<26;x++){
                for(int y =0;y<26;y++){
                    dp[i][x][y] = 1e9;
                }
            }
        }
        //base case 
        dp[0][0][str[0]-'A'] = dist(str[0]-'A',0);

        if(n==1) ans = dp[0][0][str[0]-'A'];
        else ans = 1e9;
        for(int i=1;i<n;i++){
            for(int x = 0;x<26;x++) for(int y =0;y<26;y++){
                if(dp[i-1][x][y] == 1e9) continue;
                dp[i][str[i]-'A'][y] = min(dp[i][str[i]-'A'][y],dist(str[i]-'A',x)+ dp[i-1][x][y]);
                dp[i][x][str[i]-'A'] = min(dp[i][x][str[i]-'A'],dist(str[i]-'A',y)+ dp[i-1][x][y]);
                if(i == n-1){
                    ans = min(ans,dp[i][x][str[i]-'A']);
                    ans = min(ans,dp[i][str[i]-'A'][y]);
                } 
            }
        }
        cout << ans << "\n";
    }
}