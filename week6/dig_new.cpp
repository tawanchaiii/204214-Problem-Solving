#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n,m,sx,sy,fx,fy,ans = 1e9;
string G[100];
vector<pii>star;
int bfs(int x,int y,int ax,int ay){
    queue<pair<pii,pii>>q;
    int dist[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++) dist[i][j] = 1e9;
    }
    q.push({{x,y},{0,0}}); dist[x][y] = 0;
    while(!q.empty()){
        int ux = q.front().first.first;
        int uy = q.front().first.second;
        int oi = q.front().second.first;
        int oj = q.front().second.second;
        //printf("%d %d %d %d\n",ux,uy,oi,oj);
        q.pop();
        if(ux==fx and uy==fy) return dist[ux][uy];
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0 and j==0) continue;
                if(i!=0 and j!=0) continue;
                int ii = ux+i,jj=uy+j;
                if(ii<0 || ii >=n || jj<0 || jj>=m) continue;
                if(G[ux][uy]=='*' && G[ux+oi][uy+oj] == '.' && (dist[ux][uy] + 1 < dist[ux+oi][uy+oj])){
                    dist[ux+oi][uy+oj] = dist[ux][uy] + 1;
                    q.push({{ux+oi,uy+oj},{oi,oj}});
                }
                if(G[ux][uy] != '.') continue;
                if(ax == ii && ay == jj and (dist[ux][uy] + 1 < dist[ii][jj])){
                    dist[ii][jj] = dist[ux][uy] + 1;
                    q.push({{ii,jj},{i,j}});
                }
                if(G[ii][jj] != '.') continue;
                if(dist[ux][uy] + 1 < dist[ii][jj]){
                    dist[ii][jj] = dist[ux][uy] + 1;
                    q.push({{ii,jj},{i,j}});
                }
                    
                
            }
        }
    }
    return 1e9;
}
int main(){
    cin >> n >> m;
    cin >>sx>>sy>>fx>>fy;
    sx--;sy--;fx--;fy--;
    for(int i=0;i<n;i++) cin >> G[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if(G[i][j] == '*') star.emplace_back(i,j);
        }
    }
    for(auto it:star){
        ans = min(ans,bfs(sx,sy,it.first,it.second));
    }
    if(ans!=1e9) cout << ans;
    else cout << "-1";
    return 0;

}