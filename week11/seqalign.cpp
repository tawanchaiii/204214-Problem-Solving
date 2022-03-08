#include<bits/stdc++.h>
using namespace std;
string x,y;
int dp[1000][1000];
int main(){
    cin >> x >> y;
    for(int i=1;i<=x.size();i++)
        dp[0][i] = i;
    for(int i=1;i<=y.size();i++)
        dp[i][0] = i;
    for(int i=1;i<=y.size();i++){
        for(int j=1;j<=x.size();j++){
            int ii = i-1,jj = j-1;
            if(y[ii] == x[jj])
                dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = min(min(1+dp[i-1][j],1+dp[i][j-1]),dp[i-1][j-1]+1);
            }

        }
    }
    cout << dp[y.size()][x.size()];
    return 0;

}