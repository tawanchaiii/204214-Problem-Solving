#include<bits/stdc++.h>
using namespace std;
int n;
int A[100001];
int B[100001];
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >>  A[i];
    for(int i=1;i<=n;i++){
        if(i<3) continue;
        for(int j=i-3;j>=i-13;j--){
            if(j>=0) B[i] = max(B[i],B[j]);
        }
        B[i]+=A[i];
        ans = max(ans,B[i]);
    }
    cout << ans;
}