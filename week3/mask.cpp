#include<bits/stdc++.h>
using namespace std;
    

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int b1,b2;
    vector<int>basic;
    int jum = 1;
    map<int,int>m;
    int ans[4];
    
    vector<int>teama;
    vector<int>teamb;
    for(int i =0;i<n;i++){
        int x; cin >> x;
        teama.emplace_back(x);
        m[x] = jum; jum++;
    }
    for(int i =0;i<n;i++){
        int x; cin >> x;
        teamb.emplace_back(x);
        m[x] = jum; jum++;
    }
    sort(teama.begin(),teama.end(),greater<int>());
    sort(teamb.begin(),teamb.end(),greater<int>());
    int t1 = teama[0];
    int t2 = teamb[0];
    if (t1 < t2) {ans[2] = m[t1]; b1 = t2;}
    else {ans[2] = m[t2]; b1 = t1;}
    

    
    vector<int>teamaa;
    vector<int>teambb;
    for(int i =0;i<n;i++){
        int x; cin >> x;
        teamaa.emplace_back(x);
        m[x] = jum; jum++;
    }
    for(int i =0;i<n;i++){
        int x; cin >> x;
        teambb.emplace_back(x);
        m[x] = jum; jum++;
    }
    sort(teamaa.begin(),teamaa.end(),greater<int>());
    sort(teambb.begin(),teambb.end(),greater<int>());
    t1 = teamaa[0];
    t2 = teambb[0];
    if (t1 < t2) {ans[3] = m[t1]; b2 = t2;}
    else {ans[3] = m[t2]; b2 = t1;}
    
    if (b1>b2) {
        ans[0] = m[b1];
        ans[1] = m[b2];
    }
    else{
        ans[1] = m[b1];
        ans[0] = m[b2];
    }
    for(auto ii:ans) cout << ii << " ";
   
}