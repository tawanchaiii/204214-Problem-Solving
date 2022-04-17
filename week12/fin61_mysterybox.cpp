#include<bits/stdc++.h>
using namespace std;
int n;
// 0 up
// 1 right 
// 2 down
// 3 left
string A[25];
int l[] = {-1,0,1,0};
int r[] = {0,1,0,-1};
int reflect(int status,char now){
    if(now == '/'){
        if(status == 0)
            return 1;
        else if (status == 1)
            return 0;
        else if (status == 2)
            return 3;
        else 
            return 2;
    }
    else if(now == '\\'){
        if(status == 0)
            return 3;
        else if (status == 1)
            return 2;
        else if (status == 2)
            return 1;
        else 
            return 0;
    }
    return -1;
}
void dfs(int x,int y,int status){
    // printf("%d %d\n",x,y);
    if(A[x][y] != '.')
        status = reflect(status,A[x][y]);
    int xx = x+l[status];
    int yy = y+r[status];
    if(xx>=0 && xx<n && yy>=0 && yy < n)
        dfs(xx,yy,status);
    else 
        // printf("%d %d %d\n",x,y,status);
        if(status == 0)
            cout << 3*n + n-(y) << endl;
        else if(status == 1)
            cout << 2*n + n-(x) << endl;
        else if(status == 2)
            cout << 1*n + (y+1) << endl;
        else
            cout << x+1 << endl;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    for(int i=0;i<n;i++)
        dfs(i,0,1);
    for(int i=0;i<n;i++)
        dfs(n-1,i,0);
    for(int i=0;i<n;i++)
        dfs(n-1-i,n-1,3);
    for(int i=0;i<n;i++)
        dfs(0,n-1-i,2);
    return 0;
}


/*
4
...\
....
.//.
.\.. 


*/