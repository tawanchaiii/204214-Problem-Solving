#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector<int> dist(10001, 1000); 
vector<bool> visited(10001, false);
vector<pii>G[10001];
int cnt = 0;


int main(){
    int n,R; cin >> n >> R;
    vector<pair<int,pii>>prepare;
    for(int i=1;i<=n;i++){
        int x,y; cin >> x >> y; 
        prepare.push_back({i,{x,y}});
    }
    prepare.push_back({0,{0,0}});
    prepare.push_back({n+1,{100,100}});
    for(int i=0;i<prepare.size()-1;i++){
        for(int j = i+1;j<prepare.size();j++){
            int x1 = prepare[i].second.first;
            int y1 = prepare[i].second.second;
            int x2 = prepare[j].second.first;
            int y2 = prepare[j].second.second;
            if ((double) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<=R) {
                G[prepare[i].first].push_back({1,prepare[j].first});
                G[prepare[j].first].push_back({1,prepare[i].first});
            }
        }
    }
    int target = n+1;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[0] = 0;
    q.push({dist[0], 0});
    while(!q.empty()){
        int u=q.top().second,d = q.top().first;
        q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        if (target == u){
            cout << dist[u];
        }
        for(auto vw:G[u]){
            int v = vw.second, w = vw.first;
            if(!visited[v] && w + dist[u] < dist[v]){
                dist[v] = w + dist[u];
                q.push({dist[v],v});
            }
        }
    }
    if(dist[target] == 1000) cout << "-1";
}