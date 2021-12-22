#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    list<int>l;
    while(t--){
        string str; 
        int x;
        cin >> str;
        if (str=="ri") {
            cin >> x;
            l.emplace_back(x);
        }
        else if (str=="li"){
            cin >> x;
            l.emplace_front(x);
        } 
        else if (str=="lr") {
            if (!l.empty()){
                int temp = l.front();
                l.pop_front();
                l.emplace_back(temp);
            }
        }
        else{
            if (!l.empty()){
                int temp = l.back();
                l.pop_back();
                l.emplace_front(temp);
            }
        }
    }
    for(auto it:l) cout << it << "\n";

}