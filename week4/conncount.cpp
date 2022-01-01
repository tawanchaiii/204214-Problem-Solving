#include<bits/stdc++.h>
using namespace std;
bool visited[100001];
vector<int>G[100001];
int cnt = 0;
void dfs(int u){
    visited[u] = 1;
    for(auto v:G[u]){
        if(!visited[v]) dfs(v);
    }
}
int main(){
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]) {
            dfs(i); cnt++;
        }
    }
    cout << cnt;
}