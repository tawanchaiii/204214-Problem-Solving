#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
priority_queue<pii>buy;
priority_queue<pii,vector<pii>,greater<pii>>sell;
int ans=0;
int main(){
    int t; cin >> t;
    while(t--){
        int type,rate,n; cin >> type >> rate >> n;
        if(type == 1){ // buy
            while(!sell.empty() && rate >= sell.top().first && n>0){
                int q = min(n,sell.top().second);
                ans+=q*rate;
                int oldp = sell.top().first;
                int newq = sell.top().second-q;
                sell.pop();
                if(newq!=0)
                    sell.push({oldp,newq});
                n-=q;
            }
            if(n>0)
                buy.push({rate,n});
        }
        else{ //sell
            while(!buy.empty() && buy.top().first>=rate && n>0){
                int q = min(n,buy.top().second);
                ans+=q*rate;
                int oldp = buy.top().first;
                int newq = buy.top().second-q;
                buy.pop();
                if(newq!=0)
                    buy.push({oldp,newq});
                n-=q;
            }
            if(n>0)
                sell.push({rate,n});     
        }
    }
    cout << ans;
    return 0;
}