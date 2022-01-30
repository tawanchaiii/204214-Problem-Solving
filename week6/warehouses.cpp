#include<bits/stdc++.h>
using namespace std;
int G[100005];
int n,m,k;
int fd(int x){
    if(G[x] == x) 
        return x;
    return G[x] =fd(G[x]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        G[i] = i;
    }
    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        x = fd(x);
        y = fd(y);
        G[x] = G[y]; //change head;
    }
    for(int i=0;i<k;i++){
        int start,des; cin >> start >>des;
        start = fd(start);
        des = fd(des);
        if(start == des) cout << "1\n";
        else cout << "0\n";
    }
}