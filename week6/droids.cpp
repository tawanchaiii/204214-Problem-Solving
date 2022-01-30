#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,ans=0; cin >> n >> m;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int last = -1;
    for(int i=0;i<m;i++){
        int x; cin >> x;
        auto pos2 = lower_bound(v.begin(),v.end(),x)-v.begin();
        int pos1 = pos2-1;
        if(pos1 == last)
            pos1--;
        if(pos2 == last)
            pos2++;
        //cout << pos1 << " "<< pos2 <<'\n';
        int dis1=2e9,dis2=2e9;
        if(pos1>=0 && pos1<n)
            dis1 = abs(x-v[pos1]);
        if(pos2>=0 && pos2<n)
            dis2 = abs(x-v[pos2]);
        if(dis1<=dis2){
            //cout << pos1<<endl;
            ans+=dis1;
            last = pos1;
        }
        else{
            //cout << pos2<<endl;
            ans+=dis2;
            last = pos2;
        }
    }
    cout << ans;
}