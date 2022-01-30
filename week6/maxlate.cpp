#include<bits/stdc++.h>
using namespace std;
int n,x,y,ans=0,nowdate=0;
vector<pair<int,int>> vec;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        vec.emplace_back(x,y);
    }
    sort(vec.begin(),vec.end());
    for(auto it:vec){
        int deadline = it.first;
        int duration = it.second;
        nowdate+=duration;
        int fee = (nowdate-deadline-10)*1000;
        fee = max(fee,0);
        ans = max(ans,fee);
    }
    cout << ans;
}