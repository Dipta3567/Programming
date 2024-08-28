#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);
    Node *tmp = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}
void print_Node(Node *head)
{
    Node *tmp = head;
    // cout << "The Linked List: ";
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void insert_at_head(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
int insert_at_pos(Node *&head, int pos, int val)
{
    Node *tmp = head;
    Node *newNode = new Node(val);
    if (pos == 0)
        insert_at_head(head, val);
    else
    {

        for (int i = 1; i < pos; i++)
        {
            if (tmp == NULL || tmp->next == NULL)
            {
                cout << "Invalid\n";
                return 2;
            }
            else
                tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    return 1;
}
int main()
{
    int val, op;
    Node *head = NULL;

    while (true)
    {
        
        cin >> val;
        if (val < 0)
            break;
        insert_at_tail(head, val);
    }
    int t, index, value;
    cin >> t;
    while (t--)
    {
        cin >> index >> value;
        int f = insert_at_pos(head, index, value);
        if (f != 2)
            print_Node(head);
    }
}