#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert_at_any_position(Node *&head, Node *&tail, int &cnt, int v, int p)
{
    Node *newNode = new Node(v);
    Node *tmp = head;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        cnt++;
        return;
    }
    if (p == 0)
    {
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        cnt++;
        return;
    }
    int i;
    for (i = 1; i < p; i++)
    {
        if (tmp == NULL || tmp->next == NULL)
            return;
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    if (tmp->next != NULL)
        newNode->next->prev = newNode;
    else
        tail = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
    cnt++;
}
void forward(Node *tmp)
{
    cout << "L -> ";
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void reverse(Node *tmp)
{
    cout << "R -> ";
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}
int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    int cnt=0;
    int t;
    cin >> t;
    while (t--)
    {
        int p,v;
        cin >> p >> v;
        if (p>cnt)
        cout << "Invalid\n";
        else
        {
            insert_at_any_position(head,tail,cnt,v,p);
            forward(head);
            reverse(tail);
        }


    }
    return 0;
}