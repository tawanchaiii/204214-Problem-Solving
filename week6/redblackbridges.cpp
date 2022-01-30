#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n,m,s,t;
int ans = 1e9;
vector<pii>G[500001];
int SPFA(int s,int t,int ham){
    vector<int>dist(n+1,1e9);
    queue<int>q;
    q.push(s); dist[s] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u==t) return dist[u];
        for(auto vc: G[u]){
            int v = vc.first, c = vc.second;
            if(dist[u] + 1 < dist[v] && c != ham){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return 1e9;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> s >> t;
    for(int i=0;i<m;i++){
        int u,v,c; cin >> u >> v >> c;
        G[u].emplace_back(v,c);
        G[v].emplace_back(u,c);
    }
    ans = min(ans,SPFA(s,t,1));
    ans = min(ans,SPFA(s,t,2));
    if(ans!=1e9) cout << ans;
    else cout << "-1";
}