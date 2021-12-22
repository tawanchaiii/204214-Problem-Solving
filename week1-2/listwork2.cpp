#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    list<int>v;
    list<int>::iterator it;
    while(t--){
        string x;
        int y;
        cin >> x >> y;
        if (x == "I") v.push_front(y);
        else if (x == "A") v.push_back(y);
        else if (x == "D"){ 
            if (y<=v.size()){
                it = v.begin();
                for(int i=0;i<y-1;i++) it++;
                v.erase(it);
            }
        } 
    }
    for (auto xx:v){
        cout << xx << "\n";
    }

}