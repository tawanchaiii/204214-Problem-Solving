#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
vector<pii>v;
int n;
vector<int>a;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int t; cin >> t;
        while(t--){
            int num,day; cin >> num >> day;
            v.emplace_back(day,num);
        }
        int ans=0;
        for(auto it:v){
            if(it.first>0) ans+=it.second;
        }
        for(vector<pii>::iterator it = v.begin();it<v.end();it++){
            if(it->first<=0) continue;
            it->first--;
        }
        a.emplace_back(ans);
    }
    for(auto it:a)
        cout << it << "\n";
}

/*
8
2 10 2 10 5
2 5 1 4 3
0
1 3 10
0
0
0
0
*/