#include<bits/stdc++.h>
using namespace std;
int parent[100001];
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
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> n;
    for(int i=1;i<=n;i++)
        parent[i] = i;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        if(root(i) == root(x))
            continue;
        merge(i,x);
    }
    set<int>x;
    for(int i=1;i<=n;i++){
        x.insert(root(i));
    }
    cout << x.size();

}