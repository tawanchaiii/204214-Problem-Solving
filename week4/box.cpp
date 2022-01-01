#include<bits/stdc++.h>
using namespace std;
string G[31];
int visit[35][35];
int n,m;
bool ans = 0;
void dfs(int i,int j){
    visit[i][j] = 1;
    if(j+2<=m-1 && j+1<=m-1 && G[i][j+2]=='.' && G[i+1][j+2]=='.' && !visit[i][j+1]){ //right
        dfs(i,j+1);
    }
    if(j-1>=0 && G[i][j-1]=='.' && G[i+1][j-1]=='.' && !visit[i][j-1]){ //left
        dfs(i,j-1);
    }
    if(i-1>=0 && G[i-1][j]=='.' && G[i-1][j+1]=='.' && !visit[i-1][j]){ // up
        dfs(i-1,j);
    }
    if(i+2 <= n-1 && i+1 <= n-1 &&  G[i+2][j]=='.' && G[i+2][j+1]=='.' && !visit[i+1][j]){ // down
        dfs(i+1,j);
    }
    if(i+1==n-2) ans = 1;
}
int main(){
   
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> G[i];
    }
    for(int i=0;i<m;i++){
        if(G[0][i]=='.' && G[0][i+1]=='.' && G[1][i]=='.' && G[1][i+1]=='.'){
            dfs(0,i);
            if(ans) break;
             for(int a=0;a<n;a++){
                for(int b=0;b<m;b++) visit[a][b] = 0;
            }
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << visit[i][j] << " ";
        }
        cout << "\n";
    }*/
    if(ans) cout << "yes";
    else cout << "no";
}