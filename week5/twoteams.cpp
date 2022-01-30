#include<bits/stdc++.h>
using namespace std;
int color[100001];
int parent[100001];
int findp(int u){
    if(parent[u] == u) return u;
    return parent[u] = findp(parent[u]);
}
int t = 1,ans=0,n,m;
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++)
        parent[i] = i;
    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        if(color[y]) swap(x,y);
        if(color[x]){
            if(color[y]){
                if(findp(x) == findp(y)){
                    if(color[x]!=3-color[y])
                        t = 0;
                }
                else{ // merge parent
                    parent[findp(y)] = findp(x);
                }
            }
            else{
                color[y] = 3-color[x]; // inverse color
                parent[y] = findp(x);
            }
        }
        else{
            color[x] = 1;
            color[y] = 2;
            parent[y] = findp(x);
        }
        ans+=t;
    }
    cout << ans;

}