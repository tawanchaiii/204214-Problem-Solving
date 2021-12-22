#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    while(getline(cin,str)){
        list<char>l;
        int mode=0;
        auto it = l.begin();
        int i=0;
        for(int i=0;i<str.size();i++){
            if (str[i]=='['){
                it = l.begin();
            }
            else if (str[i]==']'){
                it = l.end();
            }
            else {
                l.insert(it,str[i]);
            }
        }
        for(auto pp:l) cout << pp;
        cout << "\n";
    }

}