#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,now =0; cin >> n >> m;
    int A[n+1]; A[0] = 0;
    for(int i=1;i<=n;i++) cin >> A[i];
    for(int i=1;i<=m;i++){
        int x; cin >> x;
        now+=x;
        now = min(now,n);
        now = max(0,now+A[now]);
    }
    cout << min(now,n);
}