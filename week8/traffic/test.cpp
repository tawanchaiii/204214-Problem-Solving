#include "traffic.h"
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
vector<pii>ans;
int ar[8];
int n, k;

void solve(int a, int b, int c, int d)
{
  if (c - a == 1 || d - b == 1)
  {
    ans.push_back({a,b});
    ans.push_back({c,d});
    return;

  }
  int midx = (a+c)/2;
  int midy = (b+d)/2;
  if(traffic_query(a,b,midx,midy) != (abs(a-midx) + abs(b-midy))){
    solve(a,b,midx,midy);
  }
  if(traffic_query(midx,midy,c,d) != (abs(c-midx) + abs(d-midy))){
    solve(midx,midy,c,d);
  }
}

int main()
{
  traffic_init(&n, &k);
  /// try x axis 
  for(int i=1;i<=n;i++){
    if(traffic_query(i,1,i,n) != abs(n-1)){
      solve(i,1,i,n);
    }
    if(ans.size() == 2*k) break;
  }
  /// try y axis
  for(int i=1;i<=n;i++){
    if(traffic_query(1,i,n,i) != abs(n-1)){
      solve(1,i,n,i);
    }
    if(ans.size() == 2*k) break;
  }
  int j = 0;
  for(int i=0;i<ans.size();i++){
    ar[j] = ans[i].first; j++;
    ar[j] = ans[i].second; j++;
  }
  // for(auto it : ar){
  //   cout << it << " ";
  // }
  traffic_report(ar[0],ar[1],ar[2],ar[3],ar[4],ar[5], ar[6], ar[7]);
}
