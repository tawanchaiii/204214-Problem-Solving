#include<bits/stdc++.h>
using namespace std;
int A[20010],st[20010],ed[20010],n;
int main(){
    while(cin >> n){
        vector<int>vecst,veced;
        for(int i=1;i<=n;i++){
            cin >> A[i];
            auto pos = lower_bound(vecst.begin(),vecst.end(),A[i])-vecst.begin();
            if(pos == vecst.size())
                vecst.push_back(A[i]);
            else
                vecst[pos] = A[i];
            st[i] = vecst.size();
        }
        for(int i=n;i>=1;i--){
            auto pos = lower_bound(veced.begin(),veced.end(),A[i])-veced.begin();
            if(pos == veced.size())
                veced.push_back(A[i]);
            else
                veced[pos] = A[i];
            ed[i] = veced.size();
        }
        int ans = -1;
        for(int i=1;i<=n;i++){
            if(st[i] == ed[i])
                ans = max(ans,st[i]*2-1);
        }
        cout << ans << "\n";
    }
}