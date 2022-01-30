#include<bits/stdc++.h>
using namespace std;
vector<bool>prime(200001,true);
int main(){
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2;i*i<=200000;i++){
        if (prime[i])
        {
            for(int k=i*i;k<=200000;k+=i)
                prime[k] = 0;
        }
    }
    int l,r,ans=0; cin >> l >> r;
    for(int i=l;i<=r-2;i++){
        if(prime[i] && prime[i+2])
            ans++;
    }
    cout << ans;
}