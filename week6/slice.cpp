#include<bits/stdc++.h>
using namespace std;
int m,h,pre=0,cnt=0;
int save[500001],ans[500001];
set<int>s;
int main(){
    cin >> m;
    for(int i=1;i<=m+1;i++){
        if(i>m)
            h=0;
        else 
            cin >> h;
        for(int j=h+1;j<=pre;j++)
            ans[i-save[j]]++;
        for(int j=pre+1;j<=h;j++)
            save[j] = i;
        pre=h;
    }
    for(int i=1;i<=m;i++){
        if(ans[i]>0)
            s.insert(i);
    }
    cout << s.size() << '\n';
    for(auto it:s) cout << it << " " << ans[it] << '\n';
}