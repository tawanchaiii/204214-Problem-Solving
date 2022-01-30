#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n,t,x,y,fx,fy,ans;
vector<pii>star;
string G[25];
int bfs(int x,int y,int ax,int ay){
    queue<pii>q;
    bool visit[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            visit[i][j] = 0;
        }
    }
    q.push({x,y});
    while(!q.empty()){
        int ux = q.front().first;
        int uy = q.front().second;
        //printf("%d %d\n",ux,uy);
        q.pop();
        visit[ux][uy] = 1;
        if(ux==fx && uy == fy) return 1;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0 and j==0) continue;
                if(i!=0 and j!=0) continue;
                int ii = ux+i,jj=uy+j;
                if(ii<0 || ii >=n || jj<0 || jj>=n) continue;
                if(ii == ax && jj == ay && !visit[ii][jj])
                    q.push({ii,jj});
                if(G[ii][jj] == '.' && !visit[ii][jj])
                    q.push({ii,jj});
            }
        }

    }
    return 0;
}
int main(){
    cin >> n >> t;
    for(int i=0;i<n;i++) cin >> G[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            if(G[i][j] == 'O') star.emplace_back(i,j);
        }
    }
    while(t--){
        cin >>x>>y>>fx>>fy;
        x--;y--;fx--;fy--;
        if(star.size()!=0){
            for(auto it:star){
                ans = max(ans,bfs(x,y,it.first,it.second));
                if(ans) break;
            }
        }
        else {
            ans = max(ans,bfs(x,y,-1,-1));
        }
        if(ans) cout << "yes\n";
        else cout << "no\n";
        ans = 0;
    }
}