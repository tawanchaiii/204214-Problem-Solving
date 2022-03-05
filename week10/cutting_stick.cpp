#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l;
    while(1){
        cin >> l;
        if(!l) return 0;
        cin >> n;
        int stick[55]={0},a,st,ed,mid;
        int dp[55][55] = {};
        for(int i=1;i<=n;i++){
            cin >> stick[i];
        }
        stick[++n] = l;
        for(a=2;a<=n;a++){
            for(st=0,ed=a+st;ed<=n;st++,ed++){
                    int minn = INT_MAX,t;
                    for(mid = st+1;mid<ed;mid++){
                        t = dp[st][mid] + dp[mid][ed] + (stick[ed] - stick[st]);
                        if(t<minn) minn = t;
                    }
                dp[st][ed] = minn;
            }
           
        }
        printf("The minimum cutting is %d.\n",dp[0][n]);
    }
}