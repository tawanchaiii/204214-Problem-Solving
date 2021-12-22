#include<bits/stdc++.h>
#define SIZE 100001
using namespace std;
list<int>v[SIZE];
list<int>::iterator it;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for(int i = 0;i<t;i++){
        string str; 
        int x,y;
        cin >> str >> x >> y;
        if (str=="N"){
            v[y].emplace_back(x);
        }
        else if (str=="M"){
            v[y].splice(v[y].end(),v[x]);
            if(!v[x].empty()) v[x].clear();
        }
    }
    for(int i =0;i<SIZE;i++){
        if(!v[i].empty()){
            for(auto it :v[i]) cout << it << "\n";
        }
    }

}