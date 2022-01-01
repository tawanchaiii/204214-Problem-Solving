#include<bits/stdc++.h>
using namespace std;
string G[31];
int visit[35][35] = {0};
int n,m;
bool isminiral = 0;
bool isforest = 0;
int ans1=0,ans2=0;
void dfs(int i,int j){
    visit[i][j] = 1;
    if(G[i][j] == '$') isminiral = 1;
    if(G[i][j] == '*') isforest = 1;
    if(j+1 <= m-1 && G[i][j+1] != '#' && !visit[i][j+1]){ //right
        dfs(i,j+1);
    }
    if(j-1 >=0 && G[i][j-1] != '#' && !visit[i][j-1]){ //left
        dfs(i,j-1);
    }
    if(i-1 >=0 && G[i-1][j] != '#' && !visit[i-1][j]){ //up
        dfs(i-1,j);
    }
    if(i+1 <=n-1 && G[i+1][j] != '#' && !visit[i+1][j]){ //down
        dfs(i+1,j);
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> G[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(G[i][j] != '#'){
                dfs(i,j);
                if(isminiral && isforest) ans1++;
                else if(isminiral || isforest) ans2++;
                isminiral = 0;
                isforest = 0;
                for(int a=0;a<n;a++){
                    for(int b=0;b<m;b++) visit[a][b] = 0;
                }
            }
            
        }
    }
    cout << ans1 << " " << ans2;
}