#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main(){
    int NN; cin >> NN;
    for(int r=1;r<=NN;r++){
        int n,m,s,t; cin >> n >> m >> s >> t;
        vector<pii>G[n+1];
        for(int i=0;i<m;i++){
            int x,y,w; cin >> x >> y >> w;
            G[x].push_back({w,y});
            G[y].push_back({w,x});
        }
        vector<int>dist(n+1,2e9);
        dist[s] = 0;
        bool reach = false;
        queue<pii>q;
        q.push({dist[s],s});
        while(!q.empty()){
            int u = q.front().second; q.pop();
            for(auto it:G[u]){
                int v = it.second;
                int w = it.first;
                if(dist[u]+w < dist[v]){
                    dist[v] = dist[u]+w;
                    q.push({w,v});
                }
            }
        }
        if(dist[t] == 2e9)
            printf("Case #%d: unreachable\n",r);
        else 
            printf("Case #%d: %d\n",r,dist[t]);
    }
}