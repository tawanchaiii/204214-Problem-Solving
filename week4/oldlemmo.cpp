#include<bits/stdc++.h>
using namespace std;
string G[150];
int n,m;
int ans1=0,ans2=0;
bool isreverse = 0;
int cnt = 0;
int main(){
    cin >> m >> n;
    for(int i=0;i<n;i++){
        cin >> G[i];
    }
    int jum[130] = {0};
    for(int i=0;i<m;i++){
        if(G[n-1][i] == '$') jum[i]=1;
    }
    /*int i=0,j=9;
    int isdown = 0;
    isreverse = 0;
    while(1){
        printf("%d %d\n",i,j);
        if (G[i][j] == '@' || G[i][j] == '$' ){
            if(G[i][j] == '$') ans1++;
            break;
        }
        if (G[i][j] == '.'){
            isdown = 1;
            i++;
        }
        else {
            if(isdown && G[i][j] != '.') isdown = 0;
            else{ 
                if (!isreverse && j+1 <= m-1){
                    j++;
                }
                else if (isreverse && j-1 >= 0){
                    j--;
                }
                else if(!isreverse && j == m-1){
                    isreverse = 1;
                    j--;
                }
                else if (isreverse && j == 0){
                    isreverse = 0;
                    j++;
                }
            }
        }
    }*/
    
    for(int b=0;b<m;b++){
        int i=0,j=b;
        int isdown = 0;
        isreverse = 0;
        while(1){
            //printf("%d %d\n",i,j);
            if (G[i][j] == '@' || G[i][j] == '$' ){
                if(G[i][j] == '$') ans1++;
                break;
            }
            if (G[i][j] == '.'){
                isdown = 1;
                i++;
            }
            else {
                if(isdown && G[i][j] != '.') isdown = 0;
                else{ 
                    if (!isreverse && j+1 <= m-1){
                        j++;
                    }
                    else if (isreverse && j-1 >= 0){
                        j--;
                    }
                    else if(!isreverse && j == m-1){
                        isreverse = 1;
                        j--;
                    }
                    else if (isreverse && j == 0){
                        isreverse = 0;
                        j++;
                    }
                }
            }  
        }
        i=0,j=b;
        isdown = 0;
        isreverse = 1;
        while(1){
            //printf("%d %d\n",i,j);
            if (G[i][j] == '@' || G[i][j] == '$' ){
                if(G[i][j] == '$') ans1++;
                break;
            }
            if (G[i][j] == '.'){
                isdown = 1;
                i++;
            }
            else {
                if(isdown && G[i][j] != '.') isdown = 0;
                else{ 
                    if (!isreverse && j+1 <= m-1){
                        j++;
                    }
                    else if (isreverse && j-1 >= 0){
                        j--;
                    }
                    else if(!isreverse && j == m-1){
                        isreverse = 1;
                        j--;
                    }
                    else if (isreverse && j == 0){
                        isreverse = 0;
                        j++;
                    }
                }
            }  
        }
    }



    for(int b=0;b<m;b++){
        int i=0,j=b;
        int isdown = 0;
        isreverse = 0;
        while(1){
            //printf("%d %d\n",i,j);
            if (i == n-2 && jum[j]) {
                ans2++;
                break;
            }
            if (G[i][j] == '@' || G[i][j] == '$' ){
                if(G[i][j] == '$') ans2++;
                break;
            }
            if (G[i][j] == '.'){
                isdown = 1;
                i++;
            }
            else {
                if(isdown && G[i][j] != '.') isdown = 0;
                else{ 
                    if (!isreverse && j+1 <= m-1){
                        j++;
                    }
                    else if (isreverse && j-1 >= 0){
                        j--;
                    }
                    else if(!isreverse && j == m-1){
                        isreverse = 1;
                        j--;
                    }
                    else if (isreverse && j == 0){
                        isreverse = 0;
                        j++;
                    }
                }
            }  
        }
        i=0,j=b;
        isdown = 0;
        isreverse = 1;
        while(1){
            //printf("%d %d\n",i,j);
            if (i == n-2 && jum[j]) {
                ans2++;
                break;
            }
            if (G[i][j] == '@' || G[i][j] == '$' ){
                if(G[i][j] == '$') ans2++;
                break;
            }
            if (G[i][j] == '.'){
                isdown = 1;
                i++;
            }
            else {
                if(isdown && G[i][j] != '.') isdown = 0;
                else{ 
                    if (!isreverse && j+1 <= m-1){
                        j++;
                    }
                    else if (isreverse && j-1 >= 0){
                        j--;
                    }
                    else if(!isreverse && j == m-1){
                        isreverse = 1;
                        j--;
                    }
                    else if (isreverse && j == 0){
                        isreverse = 0;
                        j++;
                    }
                }
            }  
        }
    }
       
    
   
    cout << ans1 << " " << ans2;
}