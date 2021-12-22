#include<bits/stdc++.h>
using namespace std;
int A[30500];
int maxx = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int L,n; cin >> L >> n;
    while(n--){
        int x,y; cin >> x >> y;
        for(int i =10*x+1;i<=10*y-1;i++){
            A[i]++;
            maxx = max(A[i],maxx);
        } 
    }
    cout << maxx;
}