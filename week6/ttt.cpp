#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>G[1001];
vector<pair<int,int>>l;
bool bfs(int p){
    vector<int>color(n+1,0);
    queue<int>q;
    q.push(1); color[1] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : G[u]){
            if(u==l[p].first && v==l[p].second) continue;
            if(v==l[p].first && u==l[p].second) continue;
            if(color[u]==color[v]) 
                return false;
            if(!color[v]){
                color[v] = 3-color[u];
                q.push(v);
            }
        }
    }
    return true;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        l.emplace_back(u,v);
    }
    for(int i=0;i<m;i++){
        if(bfs(i)){
            cout<< l[i].first << " " << l[i].second;
            return 0;
        }
    }
}