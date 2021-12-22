#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>vec;
double findmedian(vector<int> vec){
    int n = vec.size();
    if (n % 2 != 0)
        return (double)vec[n / 2];
    return (double)(vec[(n - 1) / 2] + vec[n / 2]) / 2.0;
}
int main(){
    int n; cin >> n;
    vector<int>xx;
    vector<int>yy;
    while(n--){
        int x,y; cin >> x >> y;
        xx.emplace_back(y+x);
        yy.emplace_back(y-x);
    }
    sort(xx.begin(),xx.end());
    sort(yy.begin(),yy.end());
    double medx = findmedian(xx);
    double medy = findmedian(yy);
    double ans = 0;
    for(auto it:xx){
        ans+=abs((double)medx-it);
    }
    for(auto it:yy){
        ans+=abs((double)medy-it);
    }
    cout << (long long) ans;
}