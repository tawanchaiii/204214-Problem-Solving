#include<bits/stdc++.h>
using namespace std;
int n;
int dp[10010];
vector<int>task[10010];
struct Element{
    int s,t,w,tag;
}vec[10010];
void solve(){
    task[0].push_back(1);
    dp[0] = vec[0].w;
    for(int i = 1 ;i < n ; i++){
        int l = 10000;
        for(int j = i-1;j>=0;j--){
            if(vec[j].t <= vec[i].s){
                l = j; break;
            }
        }
        if(dp[i-1] < vec[i].w + dp[l]){
            dp[i] = vec[i].w + dp[l];
            if(l != 10000)
                task[i] = task[l];
            task[i].push_back(vec[i].tag);
        }
        else{
            task[i] = task[i-1];
            dp[i] = dp[i-1];
        }
    }
    cout << dp[n-1] << "\n" << task[n-1].size() << "\n";
    for(auto it : task[n-1]){
        cout << it << " ";
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> vec[i].s >> vec[i].t >> vec[i].w;
        vec[i].tag = i+1;
    }
    sort(vec,vec+n,[](Element &x, Element &y) {return x.t < y.t;});
    solve();
}
/*
3
1 3 2
2 4 10
3 5 2


3
1 3 2
2 4 3
3 5 2

*/