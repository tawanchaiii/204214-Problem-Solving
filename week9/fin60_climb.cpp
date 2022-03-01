#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>; 
string A[35];
int n,m;
int dist[35][35];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    for(int i=0;i<35;i++){
        for(int j=0;j<35;j++)
            dist[i][j] = 1e9;
    }
    queue<pii>q;
    q.push({n-1,0});
    dist[n-1][0] = 0;
    while(!q.empty()){
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0 && j==0) continue;
                if(i!=0 && j!=0) continue;
                int vx = ux + i;
                int vy = uy + j;
                if(vx<0 || vx >=n || vy<0 || vy >=m) continue;
                if(A[vx][vy] != '.') continue;
                if(i==0){ // left-right
                    if(dist[ux][uy] + 1 < dist[vx][vy]){
                        dist[vx][vy] = dist[ux][uy] + 1;
                        q.push({vx,vy});
                    }

                }
                else if (j==0){
                    if(i==-1){
                        if(dist[ux][uy] + 5 < dist[vx][vy]){
                            dist[vx][vy] = dist[ux][uy] + 5;
                            q.push({vx,vy});
                        }
                    }
                    else if(i==1){
                         if(dist[ux][uy] + 0 < dist[vx][vy]){
                            dist[vx][vy] = dist[ux][uy] + 0;
                            q.push({vx,vy});
                        }
                    }
                }
            }
        }
    }
    if(dist[0][m-1] != 1e9) cout << dist[0][m-1];
    else cout << "-1";
}