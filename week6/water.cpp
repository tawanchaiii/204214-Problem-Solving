#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0; cin >> n;
    int A[n+1]; A[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> A[i];
        if(i==1) continue;
        if(A[i-1]-A[i]>10)
            ans += min(700,10*(A[i-1]-A[i]));
    }
    cout << ans;
}