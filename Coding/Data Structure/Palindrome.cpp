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
void insert_at_tail(Node *&head, Node *&tail,int v)
{
    Node *newNode=new Node (v);
    if (head==NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    else
    {
        newNode->next=NULL;
        newNode->prev=tail;
        tail->next=newNode;
        tail=tail->next;
    }
}
bool palin(Node *head,Node *tail)
{
    Node *tmp=head,*tmp2=tail;
    while (tmp!=NULL && tmp2!=NULL)
    {
        if (tmp->val!=tmp2->val)
        return false;
        tmp=tmp->next;
        tmp2=tmp2->prev;
    }
    return true;
}
int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    int x;
    while (true)
    {
        cin >> x;
        if (x==-1)
        break;
        insert_at_tail(head,tail,x);
    }
    if (palin(head,tail))
    cout << "YES\n";
    else
    cout << "NO\n";
    return 0;
}