#include<bits/stdc++.h>
using namespace std;
bool condi(const pair<int,int> &a,const pair<int,int> &b)
{
    if (a.first != b.first) return (a.first < b.first);
    else return (a.second < b.second);
}
vector<pair<int,int>> vec;
vector<int> willfind;
int ans=0;
/*nt bs(int l,int r,int want){
    int m = (r-l)/2
    if(r < l) return m;
    else if (vec[m].first==want) return m;
    else if (vec[m]>want) return bs(l,r-1,m);
    else return bs(l+1,r,m)
}*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int L,n; cin >> L >> n;
    while(n--){
        int x,y; cin >> x >> y;
        vec.push_back({x,y});
        willfind.push_back(x);
    }
    sort(vec.begin(),vec.end(),condi);
    sort(willfind.begin(),willfind.end());
    int run = 0;
    while(1){
        int ee = vec[run].second;
        //cout << "ee = " << ee << endl;
        if (ee==L) break;
        auto it = lower_bound(willfind.begin(),willfind.end(),ee);
        run = it-willfind.begin();
        //cout << "run  = " << run << endl;
        ans++;
    }
    cout << ans;

}