#include<bits/stdc++.h>
using namespace std;
int coin[] = {1,5,10,25,50};
int n;
int ans[7500];
int main(){
    ans[0] = 1;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<5;i++){
        for(int j=0;j<=7500;j++){
            if(j>=coin[i]){
                ans[j] += ans[j-coin[i]];
            }
        }
    }
    while(cin >> n){
        cout << ans[n] << "\n";
    }
}