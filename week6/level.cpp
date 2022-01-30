#include<bits/stdc++.h>
using namespace std;
int A[2000][3];
int main(){
    int n,m; cin >> n >> m;
    for(int i=1;i<=n-1;i++){
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }
    int can=0,level=1;
    for(int i=1;i<=m;i++){
        int a,b,c; cin >> a >> b >>c;
        if(a>=A[level][0]) can = can | 1;
        if(b>=A[level][1]) can = can | 2;
        if(c>=A[level][2]) can = can | 4;
        if(can == 7){
            level++;
            can = 0;
        }
        level = min(n,level);
    }
    cout << level;
    
}