#include<bits/stdc++.h>
using namespace std;
int maxx = 0;
string save;
int getL(string str){
    int x=0,y=0;
    for(auto i : str){
        if(i=='N') y++;
        else if (i=='S') y--;
        else if (i=='E') x++;
        else if (i=='W') x--;
        else if (i=='Z') {
            x=0; y=0;
        }
    }
    return abs(x)+abs(y);
}
void recur(string str,int l){
    if(str.length()>l){
        for(int i=0;i<str.length();i++){
            string next = str;
            next = next.erase(i,1);
            recur(next,l);
        }
    }
    else{
        if(getL(str)>maxx){
            maxx = getL(str);
            save = str;
        }
    }
}
int main(){
    string x;
    int l;
    cin >> x >> l;
    recur(x,x.length()-l); cout << 2*maxx << " " << save ; 
}