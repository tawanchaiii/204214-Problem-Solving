#include<bits/stdc++.h>
using namespace std;
vector<tuple<double,int,int>>can;
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
int xx[505],yy[505];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> xx[i] >> yy[i];
        for(int j=1;j<i;j++){
           double f =  (xx[i]-xx[j]);
           double t =  (yy[i]-yy[j]);
           double dis = sqrt(f*f+t*t);
           can.push_back({dis,i,j});
        }
    }
    for(int i = 1;i<=n;i++)
        parent[i] = i;
    
    sort(can.begin(),can.end());
    double ans = 0;
    double last = 0;
    for(auto e : can){
        double w;
        int u,v;
        tie(w,u,v) = e;
        if(root(u) == root(v))
            continue;
        ans+=w;
        last = w;
        merge(u,v);
    }
    printf("%.4f",ans-last);
}