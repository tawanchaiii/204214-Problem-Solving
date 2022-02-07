#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int u,v,w;
    bool operator<(const Edge &rhs) const{
        return w < rhs.w;
    }
};
vector<Edge>edges;
int parent[300000];
int root(int u){
    if(parent[u] == u)
        return u;
    return parent[u] = root(parent[u]);
}

void merge(int u,int v){
    u = root(u), v = root(v);
    if (u==v)
        return;
    parent[u]=v;
}
int n,m;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
        parent[i] = i;
    for(int i=0;i<m;i++){
        Edge x; int u,v,w; 
        cin >> u >> v >> w;
        x.u = u;
        x.v = v;
        x.w = w;
        edges.push_back(x);
    }
    sort(edges.begin(),edges.end());
    int ans = 0;
    for(auto e : edges){
        if(root(e.u) == root(e.v))
            continue;
        ans+=e.w;
        merge(e.u,e.v);
    }
    cout << ans;
}