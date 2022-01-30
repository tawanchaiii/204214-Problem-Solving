#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
vector<int>G[100001];
vector<int>ans;
int n,m;
int indeg[100001];
int color[100001];
queue<int>q;
void bfs(){
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto v:G[u]){
            --indeg[v];
            if(!indeg[v]) q.push(v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >>v;
        G[u].push_back(v);
        indeg[v]++;
    }
    int st=-1;
    for(int i=1;i<=n;i++){
        if(!indeg[i]){ 
            st = i;
            q.push(i);
        }
    }
    if(st==-1) cout << "no";
    else {
       bfs();
       if(ans.size()<n) cout << "no";
       else for(auto i:ans) cout << i << "\n";
    }
}