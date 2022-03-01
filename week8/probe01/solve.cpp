#include "probelib.h"
#include <cstdio>
int n;
void solve(int a,int b)
{
    int mid = a + (b-a)/2;
    if (a == b)
        probe_answer(a);
    if(probe_check(a, mid)){
        solve(a,mid);
    }
    else{
        solve(mid+1,b);
    }
}
int main()
{
    int n = probe_init();
    solve(0,n-1);
}
