#include<bits/stdc++.h>
using namespace std;
int n;
int A[1100];
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> A[i];
    vector<vector<int> > L(n);
    L[0].push_back(A[0]);
    for(int i = 1; i<n;i++){
        for(int j=0;j<i;j++){
            if(A[i] > A[j] && L[i].size()<L[j].size()+1){
                L[i] = L[j];
            }
        }
        L[i].push_back(A[i]);
    }
    int maxx = L[0].size();
    int ind = 0;
    for(int i=0;i<n;i++){
        if(L[i].size() > maxx){
            maxx = L[i].size();
            ind = i;
        }
    }
    cout <<maxx<< "\n";
    for(auto it : L[ind]){
        cout << it << " ";
    }
}