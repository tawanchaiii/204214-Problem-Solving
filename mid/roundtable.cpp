#include<bits/stdc++.h>
using namespace std;
int n,ans = 0;
int A[300000];
int B[300000];
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    for(int i=0;i<n;i++){
        if(A[i] <= i){
            B[i-A[i]]++;
            ans = max(ans,B[i-A[i]]);
        }
        else{
            B[n+i-A[i]]++;
            ans = max(ans,B[n+i-A[i]]);
        }
    }
    cout << ans;
    return 0;
}