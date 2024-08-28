#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Node
{
public:
    ll val;
    Node *next;
    Node(ll val)
    {
        this->val = val;
        this->next = NULL;
    }
};
int main()
{
    Node *head = NULL;
    Node *tmp = NULL;
    while (true)
    {
        int v;
        cin >> v;
        if (v == -1)
            break;
        Node *newNode = new Node(v);
        if (head == NULL)
        {
            head = newNode;
            tmp = head;
        }
        else
        {
            tmp->next = newNode;
            tmp = tmp->next;
        }
    }
    tmp = head;
    Node *tmp1 = NULL;
    Node *prev = NULL;
    int i, j;
    for (i = 0; tmp != NULL; i++)
    {
        prev = tmp;
        tmp1 = tmp->next;
        for (j = 0; tmp1 != NULL; j++)
        {
            if (tmp->val == tmp1->val)
            {
                Node *deleteNode = tmp1;
                prev->next = tmp1->next;
                tmp1 = tmp1->next;
                delete deleteNode;
            }
            else
            {
                prev = tmp1;
                tmp1 = tmp1->next;
            }
        }
        tmp = tmp->next;
    }
    tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}