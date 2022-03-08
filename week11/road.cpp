#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main(){
    while(1){
        int n,m,sum=0; cin >> n >> m;
        if(n == 0 && m == 0) break;
        vector<pii>G[n+1];
        for(int i=0;i<m;i++){
            int x,y,w; cin >> x >> y >> w;
            sum+=w;
            G[x].push_back({w,y});
            G[y].push_back({w,x});
        }
        vector<int>dist(n+1,2e9);
        vector<bool>visit(n+1,false);
        dist[0] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        int mst = 0;
        q.push({dist[0],0});
        while(!q.empty()){
            int u = q.top().second; 
            q.pop();
            if(visit[u]) continue;
            visit[u] = true;
            mst+=dist[u];
            for(auto it:G[u]){
                int v = it.second;
                int w = it.first;
                if(!visit[v] && w < dist[v]){
                    dist[v] = w;
                    q.push({w,v});
                }
            }
        }
        cout << sum-mst <<"\n";
    }
}