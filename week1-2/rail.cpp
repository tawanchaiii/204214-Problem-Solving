#include<cstdio>
#include<stack>
using namespace std;
int N,c;
void func(){
    while(1){
        stack<int>st;
        int j=0;
        for(int i=0;i<N;i++){
            scanf("%d",&c);
            if(c==0) return;
            while(j<N && j!=c){
                if (st.size() >0 && st.top()==c) break;
                j++;
                st.push(j) ;
            }   
            if (st.top()==c) st.pop();
        }
        if(st.size()==0) printf("Yes\n");
        else printf("No\n");
    }
}
int main(){
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        func();
        printf("\n");
    }
}