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
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    // tmp ekhon last node e
    tmp->next = newNode;
}
void print_linked_list(Node *head)
{
    cout << "Your Linked List: ";
    Node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp == NULL)
        {
            return;
        }
        else
        {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
    }
    cout << endl
         << endl;
}
void insert_at_head(Node *&head, int v)
{
    Node *newNode = new Node(v);
    newNode->next = head;
    head = newNode;
    cout << endl
         << endl;
}
void insert_at_pos(Node *&head, int pos, int v)
{
    Node *newNode = new Node(v);
    Node *tmp = head;
    if (pos == 1)
        insert_at_head(head, v);
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            if (tmp == NULL)
            {
                cout << "INVALID\n\n\n";
                return;
            }
            else
                tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    cout << endl
         << endl;
}
void delete_at_head(Node *&head)
{
    if (head == NULL)
    {
        cout << "INVALID\n\n\n";
        return;
    }
    Node *tmp = head;
    Node *deleteNode = tmp;
    head = tmp->next;
    delete deleteNode;
    cout << endl
         << endl;
}
void delete_at_pos(Node *&head, int pos)
{
    Node *tmp = head;
    if (pos == 1)
        delete_at_head(head);
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            if (tmp == NULL)
            {
                cout << "INVALID\n\n\n";
                return;
            }
            else
                tmp = tmp->next;
        }
        if (tmp->next == NULL)
        {
            cout << "INVALID\n\n\n";
            return;
        }
        Node *deleteNode = tmp->next;
        tmp->next = tmp->next->next;
        delete deleteNode;
    }
    cout << endl
         << endl;
}
int count(Node *head)
{
    int cnt = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }
    // cout << "Total count: " << cnt << endl;
    return cnt;
}
void print_reverse_recursion(Node *tmp)
{
    if (tmp == NULL)
        return;
    print_reverse_recursion(tmp->next);
    cout << tmp->val << " ";
}
void sorting(Node *head, int cnt)
{
    long long int maxi = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->val > maxi)
            maxi = tmp->val;
        tmp = tmp->next;
    }
    vector<long long int> freq(maxi + 1, 0);
    tmp = head;
    while (tmp != NULL)
    {
        freq[tmp->val]++;
        tmp = tmp->next;
    }
    for (int i = 0; i <= maxi; i++)
    {
        if (freq[i] != 0)
        {
            while (freq[i]--)
                cout << i << " ";
        }
    }
}
int main()
{
    Node *head = NULL;

    while (true)
    {
        int v;
        cout << "Enter the values: ";
        cin >> v;
        if (v < 0)
        {
            cout << "\n\n";
            break;
        }
        insert_at_tail(head, v);
    }
    while (true)
    {
        cout << "Option 1: Insert at Tail" << endl;
        cout << "Option 2: Print Linked List" << endl;
        cout << "Option 3: Insert at position\n";
        cout << "Option 4: Insert at head\n";
        cout << "Option 5: Delete at pos\n";
        cout << "Option 6: Delete at head\n";
        cout << "Option 7: print reverse\n";
        cout << "Option 8: Sort the Node\n";
        cout << "Option 9: Terminate" << endl;
        int op;
        cin >> op;
        if (op == 1)
        {
            cout << "Please enter value: ";
            int v;
            cin >> v;
            insert_at_tail(head, v);
        }
        else if (op == 2)
        {
            print_linked_list(head);
        }
        else if (op == 3)
        {
            int pos, v;
            cout << "POS: ";
            cin >> pos;
            cout << "VAlue: ";
            cin >> v;
            if (pos == 0)
                insert_at_head(head, v);
            else
                insert_at_pos(head, pos, v);
        }
        else if (op == 4)
        {
            int v;
            cout << "Value: ";
            cin >> v;
            insert_at_head(head, v);
        }
        else if (op == 5)
        {
            int pos;
            cout << "Pos: ";
            cin >> pos;
            delete_at_pos(head, pos);
        }
        else if (op == 6)
        {
            delete_at_head(head);
        }
        else if (op == 7)
        {
            print_reverse_recursion(head);
            cout << endl
                 << endl;
        }
        else if (op == 8)
        {
            sorting(head, count(head));
            cout << endl;
        }
        else if (op == 9)
        {
            break;
        }
    }
    return 0;
}