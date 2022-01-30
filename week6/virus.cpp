#include<bits/stdc++.h>
using namespace std;
int n,m,x,t;
list<int>v;
list<int>::iterator it;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> x;
        v.emplace_back(x);
    }
    it = v.begin();
    while(m--){
        cin >> t;
        if(t==1) it = v.begin();
        if(t==2) {
            it++;
            if(it==v.end()) it = v.begin();
        }
        if(t==3){
            cin >> x;
            v.insert(it,x);
        }
        if(t==4){
            auto temp = it ;
            cin >> x;
            it++;
            v.insert(it,x);
            it = temp;
        }
    }
    for(auto r:v) cout << r <<'\n';
}