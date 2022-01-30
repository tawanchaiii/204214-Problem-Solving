#include<bits/stdc++.h>
using namespace std;
int n,K;
int G[1000][1000];
int visit[1000][1000];
void dfs(int x,int y){
    visit[x][y] = 1;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ii = x+i,jj = y+j;
            if(ii<0 || ii >=n || jj<0 || jj>=n) continue;
            if(G[ii][jj] - G[x][y] > K) continue;
            if(!visit[ii][jj])
                dfs(ii,jj);
        }
    }
}
int main(){
    scanf("%d%d",&n,&K);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        scanf("%d",&G[i][j]);
    }
    dfs(0,0);
    if(visit[n-1][n-1]) 
        printf("yes");
    else 
        printf("no");
    return 0;
}