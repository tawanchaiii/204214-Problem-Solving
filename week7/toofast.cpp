#include<bits/stdc++.h>
using namespace std;
using tup = tuple<int,int,int>;
int n,m;
vector<tup>G[30000];
int dist[30000][2];
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w,t; cin >> u >> v >> w >> t;
        G[u].push_back(make_tuple(w,v,t));
        G[v].push_back(make_tuple(w,u,t));
    }
    for(int i=0;i<=n;i++){
        dist[i][0] = 1e9;
        dist[i][1] = 1e9;
    }
    queue<tup>q;
    dist[1][0] = 0;
    q.push(make_tuple(dist[1][0],1,0));
    while(!q.empty()){
        auto xx = q.front(); q.pop();
        int uw,u,tu;
        tie(uw,u,tu) = xx;
        for(auto it : G[u]){
            int w,v,t;
            tie(w,v,t) = it;
            if(tu && t) continue;
            int wills = t;
            if (tu) wills = tu;
            if(uw + w < dist[v][wills]){
                dist[v][wills] = uw + w;
                q.push(make_tuple(dist[v][wills],v,wills));
            }
        }
    }
    ans = min(dist[n][0],dist[n][1]);
    if(ans == 1e9) cout << "-1";
    else cout << ans;
    return 0;
}