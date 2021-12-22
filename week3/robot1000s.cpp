#include<bits/stdc++.h>
using namespace std;
int maxx = 0;
int x=0,y=0;
int findd(string x,char y){
    for(int i=0;i<x.length();i++){
        if(x[i] == y) return i;
    }
    return -1;
}
int main(){
    string str;
    int l;
    cin >> str >> l;
    
    for(auto i : str){
        if(i=='N') y++;
        else if (i=='S') y--;
        else if (i=='E') x++;
        else if (i=='W') x--;
        else if (i=='Z') {
            x=0; y=0;
        }
    }
    for(int i=0;i<l;i++){
        if(x>0 && findd(str,'W')!=-1){
            str.erase(findd(str,'W'),1);
            x++;
        }
        else if(x<0 && findd(str,'E')!=-1){
            str.erase(findd(str,'E'),1);
            x--;
        }
        else if(y>0 && findd(str,'S')!=-1){
            str.erase(findd(str,'S'),1);
            y++;
        }
        else if(y<0 && findd(str,'N')!=-1){
            str.erase(findd(str,'S'),1);
            y--;
        }
        else{
            if(str[0]== 'N') y--;
            else if(str[0]== 'S') y++;
            else if(str[0]== 'E') x--;
            else x++;
            str.erase(0,1);
        } 
        //cout << i << " " << str << "\n";
    }
    cout << 2*(abs(x)+abs(y)) ;
}