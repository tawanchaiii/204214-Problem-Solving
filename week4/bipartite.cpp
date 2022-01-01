#include<bits/stdc++.h>
using namespace std;
int color[100001];
bool dfs(vector<int>*G,int u,int c){
    if(color[u]!=0){
        return color[u] == c;
    }
    color[u] = c;
    for(auto v : G[u]){
        if(!dfs(G,v,c == 1 ? 2:1)) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<int>G[n+1];
        memset(color,0,sizeof(color));
        bool ans = 1;
        for(int i=0;i<m;i++){
            int u,v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(color[i] == 0){
                if(!dfs(G,i,1)){
                    ans = 0;
                    break;
                }
            }
        }
        if(ans) cout << "yes\n";
        else cout << "no\n";
    }
}