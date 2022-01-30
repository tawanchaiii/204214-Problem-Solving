#include<bits/stdc++.h>
using namespace std;
string G[51];
bool visit[51][51];
int n,m;
int ax,ay,dx,dy,sx,sy;
int minn = 1e9;
int save = 1e9;
vector<pair<int,int>>vec;
void dfs(int x,int y,int cnt){
    visit[x][y] = 1;
    printf("%d %d\n",x,y);
    if(x == dx && y == dy){
        save = min(cnt,save);
    }   
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ii = x+i,jj=y+j;
            if(ii<0 || ii >=n || jj<0 || jj>=m) continue;
            if(ax == ii && ay == jj && !visit[ii][jj])
                dfs(ii,jj,cnt+1);
            if(G[ii][jj] != '.') continue;
            if(!visit[ii][jj])
                dfs(ii,jj,cnt+1);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&sx,&sy,&dx,&dy);
    sx--;sy--;dx--;dy--;
    for(int i=0;i<n;i++)
        cin >> G[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(G[i][j] == '*'){
                vec.emplace_back(i,j);
            }
        }
    }
    for(auto it : vec){
        ax = it.first, ay = it.second;
        //printf("%d %d\n",ax,ay);
        dfs(sx,sy,0);
        minn = min(minn,save);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visit[i][j] = 0;
            }   
        }
        save = 1e9;
        printf("\n");
    }
        
    
    if(minn != 1e9) printf("%d",minn);
    else printf("-1");
    return 0;
}