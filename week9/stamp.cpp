/*
3
1 3 2
2 4 3
3 5 2

3
1 3 2
2 4 10
3 5 2

*/


#include<bits/stdc++.h>
using namespace std;

int N,dp[10050] = {0}; 
vector<int> save[10000];
struct Sct {
    int st, en, w;
}xx[10000]; 
int main()
{
    cin >> N;
    for(int i=0;i<N;i++){
    	cin >> xx[i].st >> xx[i].en >> xx[i].w;
	}
    
    
    sort(xx,xx+N,[](Sct &x, Sct &y) {return x.en < y.en;});
 
    dp[0] = xx[0].w;
    save[0].push_back(0);
 
    for (int i=1;i<N;i++){
    	//printf("%d %d %d ... %d\n",xx[i].st,xx[i].en,xx[i].w,dp[i]);
    	int last = 10000;
        for(int j=i-1;j>=0;j--){
        	if( xx[j].en <= xx[i].st ){
        		last = j;
        		break;
			}
		}
 		//cout << dp[last] << "\n";
        if (dp[i-1] < xx[i].w + dp[last]){
            dp[i] = xx[i].w + dp[last];
            if (last != 10000) {
                save[i] = save[last];
            }
            save[i].push_back(i);
		}
        else {
            save[i] = save[i-1];
            dp[i] = dp[i-1];
        }
        //cout << dp[i] << "\n";
    }
 
    cout << dp[N-1] << "\n";
    cout << save[N-1].size() << "\n";
    for(auto a:save[N-1]){
    	cout << a << " ";
	}
}
