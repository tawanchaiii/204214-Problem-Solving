#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n,m,ans=0;
vector<pair<int,pii>>v;
vector<int>num;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x,y,z; cin >> x >> y >> z; // number bath quantity
        v.push_back({x,{y,z}});
    }
    sort(v.begin(),v.end());
    for(auto i : v) num.emplace_back(i.first);
    while(m--){
        int y,minn=2e9,pos=-1; cin >> y;
        auto it = lower_bound(num.begin(),num.end(),y)-num.begin();
        for(int i=it-6;i<=it+5;i++){
            if(i>=n)
                break;
            if(i<0) 
                continue;
            int ran = v[i].first, price = v[i].second.first, quan = v[i].second.second;
            if(abs(ran-y)<=5 && quan>0 && price<minn){
                 minn = price;
                 pos = i;
            } 
        }
        if(pos!=-1) {
            cout << minn << "\n";
            --v[pos].second.second;
        }
        else cout << "0\n";
    }
}