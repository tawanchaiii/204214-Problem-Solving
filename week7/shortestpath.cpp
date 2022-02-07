#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n,m;
vector<pii>G[200000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        G[u].emplace_back(w,v);
        G[v].emplace_back(w,u);
    }
    vector<bool>visit(n+1,false);
    vector<int>dist(n+1,1e9);
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    dist[1] = 0;
    pq.push({dist[1],1});
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        if(visit[u]) 
            continue;
        visit[u] = true;
        if(u == n){
            cout << dist[u];
            return 0;
        }
            
        for(auto vw:G[u]){
            int v = vw.second, w = vw.first;
            if(!visit[v] && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w ;
                pq.push({dist[v],v});
            }
        }
    }
    return 0;
}