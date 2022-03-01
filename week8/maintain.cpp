#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
vector<pii>G[201];
int n,t;
int st;
int mst(int st){
    int cnt =0 ;
    int sum = 0;
    vector<int>dist(n+1,1e9);
    vector<bool>visit(n+1,false);
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    dist[st] = 0; 
    pq.push({dist[st],st});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visit[u])
            continue;
        visit[u] = true;
        cnt++;
        sum+=dist[u];
        if(cnt == n)
            return sum;
        for(auto vw: G[u]){
            int w = vw.first;
            int v = vw.second;
            if(!visit[v] && w < dist[v]){
                dist[v] = w;
                pq.push({dist[v],v});
            }
        }

    }
    return -1;

}
int main(){
    cin >> n >> t;
    while(t--){
        int a,b,w; cin >> a >> b >> w;
        G[a].push_back({w,b});
        G[b].push_back({w,a});
        int st = a;
        cout << mst(st) << endl;
    }
}