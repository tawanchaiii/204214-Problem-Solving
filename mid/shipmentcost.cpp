#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
vector<int>G[100010];
vector<int>visit(100010,-1);
queue<pair<int,int>>q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> s >> t;
    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    for(int i=0;i<s;i++){
        int x; cin >> x;
        q.push({x,0});
        visit[x]=0;
    }
    while(!q.empty()){
        int u = q.front().first;
        int st = q.front().second;
        q.pop();
        for(auto v:G[u]){
            if(visit[v]!=-1)
                continue;
            visit[v] = st+1;
            q.push({v,visit[v]});
        }
    }
    for(int i=0;i<t;i++){
        int x; cin >> x;
        cout << visit[x] << "\n";
    }

    return 0;
}