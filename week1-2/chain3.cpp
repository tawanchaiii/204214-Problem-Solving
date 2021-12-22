#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int num;
    int status; // 1 head 2 tail 0 child
    struct node *next;
    struct node *back;
} t_node;

t_node* push(t_node **it, int num,int status)
{
    t_node *temp = (t_node *)malloc(sizeof(t_node));
    if ((*it) == NULL)
    {
        temp->num = num;
        temp->next = NULL;
        temp->back = NULL;
        temp->status = status;
        (*it) = temp;
        return *it;
    }
    else
    {
        temp->num = num;
        temp->next = NULL;
        temp->back = (*it);
        temp->status = status;
        (*it)->next = temp;
        return temp;
    }
    
}
bool is_reverse = 0;
t_node* m[150000];
bool juc[150000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    int col[n + 1];
    col[0] = 1;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        col[i] = col[i - 1] + x;
        t_node *itt = NULL;
        for (int j = col[i - 1]; j < col[i]; j++)
        {
            if (j==col[i-1]){ // head
                itt = push(&itt,j,1);
                m[itt->num] = itt;
            }
            else if (j==col[i]-1){ //tail
                itt = push(&itt,j,2);
                m[itt->num] = itt;
            }
            else { //child
                itt = push(&itt,j,0);
                m[itt->num] = itt;
            }
        }
    }
    t_node *itt = m[1]; 
    while (t--)
    {
        char menu; int value;
        cin >> menu;
        if (menu == 'F'){
            if(!is_reverse){
                if(itt->next!=NULL){
                    if(itt->next->next == itt) {
                        itt = itt->next;
                        is_reverse = 1;
                    }
                    else{
                        itt = itt->next;
                    }
                }
            }
            else{
                if(itt->back!=NULL){
                    if(itt->back->back == itt) {
                        itt = itt->back;
                        is_reverse = 0;
                    }
                    else{
                        itt = itt->back;
                    }
                }
            }
        }
        else if (menu == 'B'){
            if(is_reverse){
                if(itt->next!=NULL){
                    if(itt->next->next == itt) {
                        itt = itt->next;
                        is_reverse = 0;
                    }
                    else{
                        itt = itt->next;
                    }
                }
            }
            else{
                if(itt->back!=NULL){
                    if(itt->back->back == itt) {
                        itt = itt->back;
                        is_reverse = 1;
                    }
                    else{
                        itt = itt->back;
                    }
                }
            }   
        }
        else if (menu == 'C'){
            /* 
            wa remove
            itt now 
            tmp will append
            */
            cin >> value;
            t_node* tmp = m[value];
            bool status_wa = is_reverse;
            if(tmp->back == NULL){
                tmp->back = itt;
                t_node* wa;
                if(!is_reverse){
                    if(itt->next!=NULL && itt->next->next == itt) status_wa = 1;
                    wa = itt->next;
                    if (wa!=NULL){
                        if(!status_wa) wa->back = NULL;
                        else wa->next = NULL;
                    }
                    itt->next = tmp;
                    itt = itt->next;
                    is_reverse = 0; 
                } 
                else{
                    if(itt->back!=NULL && itt->back->back == itt) status_wa = 0;
                    wa = itt->back;
                    if (wa!=NULL){
                        if(!status_wa) wa->back = NULL;
                        else wa->next = NULL;
                    }
                    itt->back = tmp;
                    itt = itt->back;
                    is_reverse = 0;
                }
            }
            else{
                tmp->next = itt;
                t_node* wa;
                if(!is_reverse){
                    if(itt->next!=NULL && itt->next->next == itt) status_wa = 1;
                    wa = itt->next;
                    if (wa!=NULL){
                        if(!status_wa) wa->back = NULL;
                        else wa->next = NULL;
                    }
                    itt->next = tmp;
                    itt = itt->next;
                    is_reverse = 1; 
                } 
                else{
                    if(itt->back!=NULL && itt->back->back == itt) status_wa = 0;
                    wa = itt->back;
                    if (wa!=NULL){
                        if(!status_wa) wa->back = NULL;
                        else wa->next = NULL;
                    }
                    itt->back = tmp;
                    itt = itt->back;
                    is_reverse = 1; 
                }
            }
        }
        cout <<""<< itt->num << "\n";
    }
}