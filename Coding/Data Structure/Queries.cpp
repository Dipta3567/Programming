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
void print(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);
    Node *tmp = head;
    if (head == NULL)
    {

        head = newNode;
        return;
    }
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
void delete_at_pos(Node *&head, int pos)
{
    if (head == NULL)
        return;
    Node *tmp = head;
    if (pos == 0)
    {
        if (head == NULL)
            return;
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            tmp = tmp->next;
            if (tmp == NULL)
                return;
        }
        if (tmp->next == NULL)
            return;
        Node *deleteNode = tmp->next;
        tmp->next = tmp->next->next;
        delete deleteNode;
    }
}
int main()
{

    Node *head = NULL;
    Node *tmp = NULL;
    int t;
    cin >> t;
    while (t--)
    {
        int x, v;
        cin >> x >> v;
        Node *newNode = new Node(v);
        if (x == 0)
        {
            if (head == NULL)
            {

                head = newNode;
                tmp = head;
            }
            else
            {
                tmp = head;
                newNode->next = tmp;
                head = newNode;
            }
            print(head);
        }
        else if (x == 1)
        {

            insert_at_tail(head, v);

            print(head);
        }
        else if (x == 2)
        {
            delete_at_pos(head, v);
            print(head);
        }
    }

    return 0;
}