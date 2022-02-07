#include<bits/stdc++.h>
using namespace std;
int parent[100010];
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

int main(){
    int n,t; cin >> n >> t;
    for(int i=1;i<=n;i++)
        parent[i] = i;
    while(t--){
        char x;
        int a,b;
        cin >> x >> a >> b;
        if(x == 'q'){
            if(root(a) == root(b)) cout << "yes\n" ;
            else cout << "no\n";
        }
        else if(x == 'c'){
            merge(a,b);
        }
    }
}