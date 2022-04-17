#include<bits/stdc++.h>
using namespace std;
string s,t;
int main(){
    cin >> s >> t;
    int ans = 0;
    int pos = 0;
    for(int i=0;i<t.size();i++){
        if(s[pos] == t[i])
            pos++;
        if(pos == s.size()){
            ans++;
            pos = 0;
        }
    }
    cout << ans;
    return 0;
}