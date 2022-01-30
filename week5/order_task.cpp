#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n,m;
int indeg[100001];
int color[100001];
void bfs(vector<int>G[]){
    queue<int>q;
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(!indeg[i]){ 
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto v:G[u]){
            --indeg[v];
            if(!indeg[v]) q.push(v);
        }
    }
    for(auto i:ans) cout << i << " ";
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        cin >> n >> m;
        if (n==0&&m==0) break;
        vector<int>G[n+1];
        for(int i=0;i<m;i++){
            int u,v; cin >> u >>v;
            G[u].push_back(v);
            indeg[v]++;
        }
        bfs(G);
        memset(indeg,0,sizeof(indeg));
    }
    
}