#include<bits/stdc++.h>
using namespace std;
string G[121];
int dp[121][121][3];
int cnt1,cnt2,m,n;
int dfs(int y,int x,int state){
    if(dp[y][x][state]!=-1) 
        return dp[y][x][state];
    if(x==0) 
        state = 2;
    if(x==n-1) 
        state = 0;
    if(G[y][x] == '$') 
        return dp[y][x][state] = 1;
    if(G[y][x] == '@') 
        return dp[y][x][state] = 0;
    if(G[y][x] == '.')
        return dp[y][x][state] = dfs(y+1,x,state);
    return dp[y][x][state] = dfs(y,x+state-1,state);

} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m; // n horizon  m verticle
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++) cin >> G[i];
    for(int i=0;i<n;i++){
        cnt1 += dfs(0,i,0);
        cnt1 += dfs(0,i,2);
    }
    for(int i=0;i<m-1;i++) for(int j=0;j<n;j++){
        int will = 0;
        if(G[i][j] == '#'){
            G[i][j] = '.';
            memset(dp,-1,sizeof(dp));
            for(int k=0;k<n;k++){
                will += dfs(0,k,0);
                will += dfs(0,k,2);
            }
            G[i][j] = '#';
            cnt2 = max(will,cnt2);
        }
    }
    cout << cnt1 << " " << cnt2;
}