#include<bits/stdc++.h>
using namespace std;
pair<double,double> P[1500];
int n,r;
int main(){
    int t=1;
    while(1){
        cin >> n >> r;
        if(n==0 && r==0) break;
        int can = 1;
        for(int i=0;i<n;i++){
            int x,y; cin >> x >> y;
            if(y>r) can = 0;
            P[i].first = x-sqrt(r*r-y*y);
            P[i].second = x+sqrt(r*r-y*y);
        }
        if(!can) {
            printf("Case %d: -1\n",t);
            t++;
            continue;
        }
        sort(P,P+n);
        int ans=0;
        int i=0;
        double d;
        while(i<n){
            d = P[i].second;
            ans++;
            while(i<n && P[i].first <= d){
                if(d>P[i].second)
                    d = P[i].second;
                i++;
            }
        }
       printf("Case %d: %d\n",t,ans);
       t++;
    }
}