#include<bits/stdc++.h>
using namespace std;
int main(){
    string x; cin >> x;
    int mode = 0;
    vector<char> ans;
    for (auto it : x){
        if(it == 'Z') {ans.push_back('Z'); mode = 0;}
        else{
            if(it=='N') {  
                while(mode%4!=0){
                    ans.push_back('R');
                    ++mode;
                    mode = mode%4;
                }
            }
            else if(it=='E') {  
                while(mode%4!=1){
                    ans.push_back('R');
                    ++mode;
                    mode = mode%4;
                }
            }
            else if(it=='S') {  
                while(mode%4!=2){
                    ans.push_back('R');
                    ++mode;
                    mode = mode%4;
                }
            }
            else if(it=='W') {  
                while(mode%4!=3){
                    ans.push_back('R');
                    ++mode;
                    mode = mode%4;
                }
            }
            ans.push_back('F');
        }
    }
    for (auto it:ans) cout << it;
}