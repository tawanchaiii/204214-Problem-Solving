#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        int n; cin >> n;
        if(!n) break;
        vector<int>v;
        for(int i=1;i<=n;i++) v.push_back(i);
        cout << "Discarded cards: ";
        while(v.size() != 1){
            if (v.size()!=2) cout << v[0] << ", ";
            else  cout << v[0];
            v.erase(v.begin());
            int temp = v[0];
            v.push_back(temp);
            v.erase(v.begin());
        }
        cout << "\n";
        cout << "Remaining card: " << v[0] << "\n";
    }
}