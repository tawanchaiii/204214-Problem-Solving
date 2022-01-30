#include<bits/stdc++.h>
using namespace std;
string want,x;
int main(){
    cin >> want >> x;
    int cnt=0,now=0;
    for(int i=0;i<x.size();i++){
        if(x[i] == want[now]) now++;
        if(now == want.size()) {cnt++; now=0;}
    }
    cout << cnt;
}