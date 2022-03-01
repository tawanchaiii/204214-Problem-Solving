#include<bits/stdc++.h>
using namespace std;
long long  n;
long long  x[100010];
long long  tmp[100010];
long long merge(long long  left,long long  mid,long long  right){
    long long  i = left;
    long long  j = mid;
    long long  k = left;
    long long  cnt = 0;
    while((i<=mid-1) && (j<=right)){
        if(x[i] <= x[j]){
            tmp[k++] = x[i++];
        }
        else{
            tmp[k++] = x[j++];
            cnt += (mid-i);
        }
    }
    while(i<=mid-1)
        tmp[k++] = x[i++];
    while(j<=right)
        tmp[k++] = x[j++];
    for(i=left;i<=right;i++)
        x[i] = tmp[i];
    return cnt;
}
long long merge_sort(long long  left,long long  right){
    long long  mid,cnt = 0;
    if(right > left){
        mid = (left+right)/2;
        cnt += merge_sort(left,mid);
        cnt += merge_sort(mid+1,right);
        cnt += merge(left,mid+1,right);
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(long long  i=0;i<n;i++){
        cin >> x[i];
    }
    cout << merge_sort(0,n-1);
    return 0;
}