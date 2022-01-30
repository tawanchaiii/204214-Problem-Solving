#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int> ;
vector<pii>v;
int cnt=1;
int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        int x,y; cin>>x>>y;
        v.emplace_back(y,x);
    }
    sort(v.begin(),v.end());
    int now = 0;
    while(1){
        int last = v[now].first;
        int j = now+1;
        while(j<=n-1){
            if (last<=v[j].second){
                cnt++;
                break;
            } 
            j++;
        }
        now = j;
        if(now == n) break;
    }
    cout << cnt;
}