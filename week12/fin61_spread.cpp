#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int u,v,w;
    bool operator<(const Edge &rhs) const{
        return w < rhs.w;
    }
};
vector<Edge>can;
int parent[300000];
int root(int u){
    if(parent[u] == u)
        return u;
    return parent[u] = root(parent[u]);
}
int n,m,x;
int sp[100005];
int main(){
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        parent[i] = i;
        cin >> sp[i];
    }
    for(int i=1;i<=m;i++){
        Edge x; int u,v,w; 
        cin >> u >> v >> w;
        double real = (double)w/(sp[u]+sp[v]);
        real = ceil(real);
        x.u = u;
        x.v = v;
        x.w = real;
        can.push_back(x);
    }
    sort(can.begin(),can.end());
    int ans = 0;
    for(auto e : can){
        if(root(e.u) == root(e.v))
            continue;
        int u,v;
        u = root(e.u), v = root(e.v);
        parent[u]=v;
        ans = max(ans,e.w);
    }
    cout << ans;
}