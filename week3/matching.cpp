#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    vector<int>vec;
    vec.emplace_back(0);
    while(n--){
        int x; cin >> x;
        vec.emplace_back(x);
    }
    while(q--){
        int ind,x; cin >> ind >> x;
        auto it = lower_bound(vec.begin(),vec.end(),vec[ind]+x);
        if (*it != vec[ind]+x ) it--;
        cout << it-vec.begin()<<"\n";
    }
}