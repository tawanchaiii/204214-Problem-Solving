#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int num;
    int status; // 1 head 2 tail 3 child
    int is_reverse;
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
        temp->is_reverse = 0;
        (*it) = temp;
        return *it;
    }
    else
    {
        temp->num = num;
        temp->next = NULL;
        temp->back = (*it);
        temp->status = status;
        temp->is_reverse = 0;
        (*it)->next = temp;
        return temp;
    }
    
}
int glore = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,t_node*>m;
    map<int,int>opposite;
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
                opposite[col[i-1]] = col[i]-1;
            }
            else if (j==col[i]-1){ //tail
                itt = push(&itt,j,2);
                m[itt->num] = itt;
                opposite[col[i]-1] = col[i-1];
            }
            else { //child
                itt = push(&itt,j,0);
            }
        }
    }
    t_node *itt = m[1]; glore = 1;
    while (t--)
    {
        char menu; int value;
        cin >> menu;
        if (menu == 'F'){
            if(itt->status == 1 && itt->is_reverse == 0) {
                if(itt->next!=NULL) {
                    itt=itt->next;
                    glore = 1;
                }
            }
            else if(itt->status == 2 && itt->is_reverse == 0) {
                if(itt->next!=NULL){
                    itt=itt->next;
                    glore = 1;
                } 
            }
            else if(itt->status == 1 && itt->is_reverse == 1) {
                if(itt->back!=NULL){
                    itt=itt->back;
                    glore = 2;
                } 
            }
            else if(itt->status == 2 && itt->is_reverse == 1) {
                if(itt->back!=NULL){
                    itt=itt->back;
                    glore = 2;
                }
            }
            else {
                if(glore==1 && itt->next!=NULL) itt = itt->next;
                else if(glore==2 && itt->back!=NULL) itt = itt->back;
            }
            
        }
        else if (menu == 'B'){
            if(itt->status == 1 && itt->is_reverse == 0) {
                if(itt->back!=NULL) {
                    itt=itt->back;
                    glore = 1;
                }
            }
            else if(itt->status == 2 && itt->is_reverse == 0) {
                if(itt->back!=NULL){
                    itt=itt->back;
                    glore = 1;
                } 
            }
            else if(itt->status == 1 && itt->is_reverse == 1) {
                if(itt->next!=NULL){
                    itt=itt->next;
                    glore = 2;
                } 
            }
            else if(itt->status == 2 && itt->is_reverse == 1) {
                if(itt->next!=NULL){
                    itt=itt->next;
                    glore = 2;
                }
            }
            else {
                if(glore==1 && itt->back!=NULL) itt = itt->back;
                else if(glore==2 && itt->next!=NULL) itt = itt->next;
            }
        }
        else if (menu == 'C'){
            cin >> value;
            t_node *tmp = m[value];
            int opp = opposite[value]; 
            if(itt->status==1 || (itt->status==0 && glore == 1)){  
                t_node* willsave = itt->next;
                itt->next = tmp;
                if(tmp->status==1) tmp->back = itt;
                else tmp->next = itt;
                // line cut 
                opposite[willsave->num] = opposite[1];
                opposite[opposite[1]] = willsave->num;
                // line new
                opposite[1] = opp;
                opposite[opp] = 1;
                if(willsave->status==0) willsave->status = glore;
                m[willsave->num] = willsave;

                auto will_delete = m.find(value);
                m.erase(will_delete);
                if(itt->next->status == 2) {
                    t_node *y = m[opposite[1]];
                    itt->next->is_reverse=1;
                    y->is_reverse = 1;
                }
                itt = itt->next;
            }
            else if(itt->status==2 || (itt->status==0 && glore == 2)){
                t_node* willsave = itt->back;
                itt->back = tmp;
                if(tmp->status==1) tmp->back = itt;
                else tmp->next = itt;

                // line cut 
                opposite[willsave->num] = opposite[1];
                opposite[opposite[1]] = willsave->num;
                // line new
                opposite[1] = opp;
                opposite[opp] = 1;

                if(willsave->status==0) willsave->status = glore;
                m[willsave->num] = willsave;
                auto will_delete = m.find(value);
                m.erase(will_delete);
                if(itt->back->status == 2) {
                    t_node *y = m[opposite[1]];
                    itt->back->is_reverse=1;
                    y->is_reverse = 1;
                }
                itt = itt->back;
            }
            
        }
        for(auto mm:m){
            int chk = 0;
            t_node *tt = mm.second;
            chk = tt->status;
            while(tt!=NULL){
                cout << tt->num << " ";
                if(tt->status == 1 && tt->is_reverse==0) {tt = tt->next; chk=1;}
                else if (tt->status == 1 && tt->is_reverse==1) {tt = tt->back; chk=2;}
                else if (tt->status == 2 && tt->is_reverse==0) {tt = tt->next; chk=1;}
                else if (tt->status == 2 && tt->is_reverse==1) {tt = tt->back; chk=2; }
                else if (tt->status == 0 && chk==1) tt = tt->next;
                else if (tt->status == 0 && chk==2) tt = tt->back;   
            }
            cout << "\n";
        }
        cout << "----------it = "  << itt->num << "\n";
    }

    /*for(auto mm:m){
        t_node *tt = mm.second;
        if(tt->status == 2){
            while(tt!=NULL){
                printf("%d ",tt->num);
                tt = tt->back;
            }
            printf("\n");
        }
    }*/
}