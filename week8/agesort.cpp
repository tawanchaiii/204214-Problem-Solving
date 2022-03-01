#include<bits/stdc++.h>
using namespace std;
int cnt[105],t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> t , t){
        int x; 
        for(int i=0;i<t;i++){
            cin >> x;
            cnt[x]++;
        }
        string y = "";
        for(int i=1;i<=100;i++){
            cnt[i]++;
            while(--cnt[i]){
                cout << y << i;
                y = " ";
            }
        }
        cout << "\n";
    }
}
