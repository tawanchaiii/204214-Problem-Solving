#include<bits/stdc++.h>
using namespace std;
vector<int>minn,re;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    minn.emplace_back(1e9+1);
    re.emplace_back(1e9+1);
    int n,q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        int x; cin >> x; 
        int tmp = min(minn[i-1],x);
        minn.emplace_back(tmp);
        re.emplace_back(tmp);
    }
    reverse(re.begin(),re.end());
    while(q--){
        int menu, value;
        cin >> menu >> value;
        if(menu == 1) cout << minn[value] << "\n";
        else {
            auto it = lower_bound(re.begin(),re.end(),value);
            cout << n - (it-re.begin())  << "\n";
        }
        
    }
}