#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using namespace std;
int m,n,ans1,ans2;
string s[121];
bool visited[121][121][3];
queue<pair<pii,pii>> q;
void bfs(int aa,int bb){
    while(!q.empty())
    {
        int x = q.front().first.first,y = q.front().first.second,d = q.front().second.first,b = q.front().second.second;
        q.pop();
        for(int i = -1;i <= 0;i++) for(int j = -1;j <= 1;j++)
        {
            visited[x][y][d+1] = true;
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            if(x==0 and i==-1) continue;
            if(j!=0 and j!=d) continue;
            int ai = x+i,aj = y+j,ad = d,ab = b;
            if((y==0 and d==-1)or(y==n-1 and d==1)){
                 aj = y; ad = -d; }
            //if(i==-1 and s[ai][aj]!='.') continue;
            if(i==-1 and s[ai][aj]!='.' && ai!=aa && aj!=bb) continue;
            if(s[ai][aj]=='@') continue;
            if(i!=-1 and s[ai][aj]=='.') continue;
            if(visited[ai][aj][ad+1]) continue;
            if(ai==0 && (aj==0 || aj==n-1)){
                q.push({{ai,aj},{-1,ab}});
                q.push({{ai,aj},{1,ab}});
            }
            else q.push({{ai,aj},{ad,ab}});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < m;i++) cin >> s[i];
    for(int i = 0;i < n;i++)
    {
        if(s[m-1][i]!='$') continue;
        q.push({{m-1,i},{-1,0}});
        q.push({{m-1,i},{1,0}});
        visited[m-1][i][0] = true;
        visited[m-1][i][2] = true;
    }
    bfs(-1,-1);
    for(int i = 0;i < n;i++) 
    {
        if(visited[0][i][0]){ ans1++;}
        if(visited[0][i][2]){ ans1++;}
    }
    memset(visited, 0, sizeof(visited[0][0][0]) * m * n*3);
    for(int aa=0;aa<m-1;aa++) {
        for(int bb=0;bb<n;bb++){
            cout << aa<< " " << bb << endl;
            int willans = 0;
            queue<pair<pii,pii>> emp;
            q.swap(emp);
            for(int i = 0;i < n;i++)
            {
                if(s[m-1][i]!='$') continue;
                q.push({{m-1,i},{-1,0}});
                q.push({{m-1,i},{1,0}});
                visited[m-1][i][0] = true;
                visited[m-1][i][2] = true;
            }
            bfs(aa,bb);
            for(int i = 0;i < n;i++) 
            {
                if(visited[0][i][0]){ willans++;}
                if(visited[0][i][2]){ willans++;}
            }
            ans2 = max(willans,ans2);
            memset(visited, 0, sizeof(visited[0][0][0]) * m * n*3);
        }
    }
    
    cout << ans1 << ' ' << ans2;

}