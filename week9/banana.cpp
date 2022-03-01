#include<bits/stdc++.h>
using namespace std;
int n;
int A[100001];
int B[100001];
int ans ;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >>  A[i];
        if(i<3) continue;
        B[i] = max(B[i-3]+A[i],B[i-1]);
        ans = max(ans,B[i]);
    }
    cout << ans;
}