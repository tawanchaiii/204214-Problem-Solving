#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int finish; cin >> finish;
        vector<pii>S;
        while(1){
            int l,r; cin >> l >> r;
            S.emplace_back(l,r);
            if(l==0 && r==0) break;
        }
        sort(S.begin(),S.end());
        vector<pii>seg;
        int curL=0,reach=0;
        while(reach<finish){
            int newL = curL;
            int far = 0;
            for(int i=1;i<S.size();i++){
                if(S[i].first > curL) 
                    break;
                else if (S[i].second > newL){
                    newL = S[i].second;
                    far = i;
                }
            }
            if(!far) break;
            seg.push_back(S[far]);
            curL = reach = newL;
        }
        if(reach >= finish){
            cout << seg.size() << "\n";
            for(auto it : seg) 
                cout << it.first << " " << it.second << "\n";
        }
        else cout << "0\n";
        if(t) cout << "\n";
    }
}