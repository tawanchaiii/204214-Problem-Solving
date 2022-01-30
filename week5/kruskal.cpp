#include<bits/stdc++.h>
using namespace std;
int parent[1000];
struct Edge{
    int u,v,w;
    bool operator<(const Edge &rhs) const{
        return w < rhs.w;
    }
};
int findp(int u){
    if(parent[u] == u) return u;
    return parent[u] = findp(parent[u]);
}
void merged(int u ,int v){
    if (findp(u) != findp(v))
        parent[u] = v;
}
vector<Edge>G;
int main(){
    int n,m,mst = 0;
    cin >> n >> m;
    for(int i=0;i<=n;i++) parent[i] = i;
    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        Edge e;
        e.u=u; e.v=v; e.w=w;
        G.emplace_back(e);
    }
    sort(G.begin(),G.end());
    for(auto e : G){
        if(findp(e.u) == findp(e.v))
            continue;
        mst+=e.w;
        merged(e.u,e.v);
    }
    cout << mst;
}

/*
input : 
4 5
1 2 99
2 4 1
1 4 4
3 4 5
2 3 11

output:
10
*/
