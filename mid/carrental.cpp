#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int k,n,maxx = -1;
int ans =2e9;
vector<pair<int,pii>> v;
vector<int>cargo;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n;
    for(int i=0;i<k;i++){
        int c,p,w; cin >> c>>p>>w;
        v.push_back({c,{p,w}});
    }
    for(int i=0;i<n;i++){
        int x; cin >> x;
        cargo.emplace_back(x);
        maxx = max(x,maxx);
    }
    for(auto t:v){
        if(t.second.second < maxx) continue;
        int sum = 0,cnt=0;
        for(auto c : cargo){
            if(sum+c> t.second.second){
                sum=0;
                cnt++;
            }
            sum+=c;
        }
        if(sum!=0) cnt++;
        ans = min(ans,t.first + cnt*t.second.first);
    }
    cout << ans;
    return 0;
}