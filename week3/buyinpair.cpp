#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long>vec;
    int n; long long a,b;
    cin >> n >> a >> b;
    long long ans = 0;
    for(int i=0;i<n;i++) {
        long long x; cin >> x;
        vec.emplace_back(x);
    }
    sort(vec.begin(),vec.end());
    for(auto ii = vec.begin();ii<vec.end();ii++){
        auto its = lower_bound(ii,vec.end(),a-*ii);
        auto itf = upper_bound(ii,vec.end(),b-*ii);
        if(its == ii) its++;
        long long x = itf-its;
        if(x>0) ans+= x;
    }
    cout << ans;
}