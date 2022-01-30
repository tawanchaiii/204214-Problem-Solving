#include<bits/stdc++.h>
using namespace std;
int want;
bool s = false;
priority_queue<int,vector<int>,greater<int>>pq;
int main(){
    cin >> want;
    while(1){
        int x; cin >> x;
        if(!x) break;
        pq.push(x);
    }
    for(int i=2559;i<=want;i++){
        if(!pq.empty() && i==pq.top()) {
            pq.pop();
            continue;
        }
        s=!s;
    }
    if(s) cout << "C";
    else cout << "K";
    return 0;
}