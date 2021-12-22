#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int num;
    int is_reverse;
    struct node *next;
    struct node *back;
} t_node;
typedef struct linked_list
{
    t_node *head;
    t_node *tail;
    int front;
    int end;
} t_list;
void push(linked_list **it, int num)
{
    node *temp = (node *)malloc(sizeof(node));
    if ((*it)->tail == NULL)
    {
        temp->num = num;
        temp->is_reverse = 0;
        temp->next = NULL;
        temp->back = NULL;
        (*it)->head = temp;
        (*it)->tail = temp;
    }
    else
    {
        temp->num = num;
        temp->is_reverse = 0;
        temp->next = NULL;
        temp->back = (*it)->tail;
        (*it)->tail->next = temp;
        (*it)->tail = (*it)->tail->next;
    }
}
int glore = 0;
int main()
{
    vector<t_list *> vec;
    int n, t;
    scanf("%d %d", &n, &t);
    int col[n + 1];
    col[0] = 1;
    int x;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        col[i] = col[i - 1] + x;
        t_list *ll = (t_list *)malloc(sizeof(t_list));
        ll->head = NULL;
        ll->tail = NULL;
        for (int j = col[i - 1]; j < col[i]; j++)
        {
            push(&ll, j);
        }
        ll->front = col[i - 1];
        ll->end = col[i];
        vec.emplace_back(ll);
    }
    t_node *it = vec[0]->head;
    while (t--)
    {
        char menu;
        int value;
        cin >> menu;
        if (menu == 'F')
        {
            if (it->next != NULL && glore % 2 == 0)
            {
                // cout << "one\n";
                if (it->is_reverse == 0 && it->next->is_reverse == 1)
                {
                    glore++;
                    glore = glore % 2;
                }
                it = it->next;
            }
            else if (it->back != NULL && glore % 2 == 1)
            {
                // cout << "two\n";
                if (it->is_reverse == 0 && it->back->is_reverse == 1)
                {
                    glore++;
                    glore = glore % 2;
                }
                it = it->back;
            }
        }
        else if (menu == 'B')
        {
            if (it->back != NULL && glore % 2 == 0)
            {
                if (it->is_reverse == 1 && it->back->is_reverse == 0)
                {
                    glore++;
                    glore = glore % 2;
                }
                it = it->back;
            }

            else if (it->next != NULL && glore % 2 == 1)
            {
                if (it->is_reverse == 1 && it->back->is_reverse == 0)
                {
                    glore++;
                    glore = glore % 2;
                }
                it = it->next;
            }
        }
        else if (menu == 'C')
        {
            cin >> value;
            int isreverse = 0;
            int cnt = 0;
            t_node *tid = NULL;
            for (auto tt : vec)
            {
                if (value == tt->front)
                {
                    tid = tt->head;
                    break;
                }
                else if (value == tt->end - 1)
                {
                    tid = tt->tail;
                    isreverse = 1;
                    break;
                }
                cnt++;
            }
            if (!isreverse && glore == 0) // 1 2 3
            {
                t_node *temp = it->next;
                t_list *ll = (t_list *)malloc(sizeof(t_list));
                ll->head = temp;
                vec.emplace_back(ll);
                it->next = tid;
                it = it->next;
            }
            else if (!isreverse && glore == 1) // 9 8 7 10 11
            {
                t_node *temp = it->back;
                t_list *ll = (t_list *)malloc(sizeof(t_list));
                ll->head = temp;
                vec.emplace_back(ll);
                it->back = tid;
                it->back->is_reverse = 1;
                it = it->back;
                glore++;
                glore = glore % 2;
            }
            else if (isreverse && glore == 0) // 1 2 3 9 8 7
            {
                t_node *temp = it->next;
                t_list *ll = (t_list *)malloc(sizeof(t_list));
                ll->head = temp;
                vec.emplace_back(ll);
                it->next = tid;
                it->next->is_reverse = 1;
                it = it->next;
                glore++;
                glore = glore % 2;
            }
            else // 9 8 7 6
            {
                t_node *temp = it->back;
                t_list *ll = (t_list *)malloc(sizeof(t_list));
                ll->head = temp;
                vec.emplace_back(ll);
                it->back = tid;
                it = it->back;
            }

            vec.erase(vec.begin() + cnt);
        }
        // cout << "Glore = " << glore << "\n";
    }
    t_node *ee = vec[0]->head;
    int re = 0;
    /*while (ee != NULL)
    {
        printf("%d ", ee->num);
        if (ee->is_reverse)
        {
            re++;
            re = re % 2;
        }
        if (re % 2 == 0)
            ee = ee->next;
        else
        {
            ee = ee->back;
        }
    }*/
    re = 0;
    for (auto gx: vec)
    {
        t_node *ee = gx->head;

        while (ee != NULL)
        {
            printf("%d ", ee->num);
            if (ee->is_reverse)
            {
                re++;
                re = re % 2;
            }
            if (re % 2 == 0)
                ee = ee->next;
            else
            {
                ee = ee->back;
            }
        }
        printf("\n");
    }
    cout << "it = " << it->num;
}