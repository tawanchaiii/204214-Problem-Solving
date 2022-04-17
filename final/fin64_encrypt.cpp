#include<bits/stdc++.h>
using namespace std;
int n,s;
vector<int>l;
int main(){
    cin >> n >> s;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        l.push_back(x);
    }
    int ee = l.size();
    for(int i=1;i<=20-ee;i++){
        l.push_back(i);
    }
    for(int i=0;i<s;i++){
        int t = l.back();
        l.pop_back();
        l.insert(l.begin(),t);
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            cout << l[j*5+i] << " ";   
        }
    }
    return 0;
}