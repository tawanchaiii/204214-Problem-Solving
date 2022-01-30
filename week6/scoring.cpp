#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t,ans=0; cin >> n >> t;
    priority_queue<int>pq[n+1];
    for(int i=0;i<t;i++){
        int x,score; cin >> x >> score;
        if(pq[x].size() < 5) pq[x].push(score);
        else pq[x].push(2e9);
    }
    for(int i=1;i<=n;i++){
        if(!pq[i].empty() && pq[i].top()!=2e9)
            ans+=pq[i].top();
    }
    cout << ans;
}