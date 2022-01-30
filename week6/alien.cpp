#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,r,ans=0; cin >>n>>a>>b>>r;
    while(n--){
        int x,y; cin >> x >> y;
        if((a-x)*(a-x) + (b-y)*(b-y)<=r*r) ans++;
    }
    cout << ans;
}