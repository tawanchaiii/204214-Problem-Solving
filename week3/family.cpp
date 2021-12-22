#include<bits/stdc++.h>
using namespace std;
int A[1001] = {-1};
int recur(int from,int dest){
    
    if(A[from] == -1) return -1;
    if(A[from] == dest) return dest;
    else return recur(A[from],dest);

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    for(int i = 2;i<=n;i++){
        int x; cin >> x; 
        A[i] = x;
    }
    while(m--){
        int from,dest; cin >> from >> dest;
        int t1 = recur(from,dest);
        int t2 = recur(dest,from);
        if(t1 == -1 && t2 == -1) cout << "-1" << "\n";
        else if (t1 != -1 && t2 == -1) cout << t1 << "\n";
        else if (t1 == -1 && t2 != -1) cout << t2 << "\n";
    }
}