#include<bits/stdc++.h>
using namespace std;
list<int>l[300001];
int jum[300001];
int findd(int n){
    int xx = jum[n];
    if (xx == n) return n;
    return findd(xx);
}
int main(){
    int now = 1;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        l[i].emplace_back(i);
        jum[i] = i;
    } 
    for(int u=1;u<=n-1;u++){
        int x,y; cin >> x >> y;
        auto it = l[findd(y)].begin();
        while(1){
            if (*it == y) break;
            it++;
        }
        it++;
        l[findd(y)].splice(it,l[findd(x)]);
        jum[x] = jum[y];
    }
    for(auto xx : l[findd(1)]) cout << xx << " ";
}