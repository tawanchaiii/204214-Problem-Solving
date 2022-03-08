#include<bits/stdc++.h>
using namespace std;
pair<int,int> A[3001];
vector<int>s;
int n,x;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        A[x-1].first = i;
    }
    for(int i=0;i<n;i++){
        cin >> x;
        A[x-1].second = i;
    }
    sort(A,A+n);
    for(int i=0;i<n;i++){
        auto it = lower_bound(s.begin(),s.end(),A[i].second);
        if(it == s.end()) s.emplace_back(A[i].second);
        else *it = A[i].second;
    }
    cout <<  s.size();
    
}