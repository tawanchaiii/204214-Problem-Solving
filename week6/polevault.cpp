#include<bits/stdc++.h>
using namespace std;
int n,q;
int A[100005];
set<int>s;
vector<char>ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> A[i];
        A[i] = A[i] + A[i-1];
        s.insert(A[i]); 
    } 
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) {
            s.insert(A[j]-A[i]);
        }
    }
    while(q--){
        int x; cin >> x;
        if(s.find(x)!=s.end()) ans.push_back('Y');
        else ans.push_back('N');
    }
    for(auto it : ans) cout << it; 
}