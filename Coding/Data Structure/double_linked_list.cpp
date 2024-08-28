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
void insert_at_head(Node *&head, Node *&tail, int val, int &cnt)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        cnt++;
        return;
    }
    else
    {
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        cnt++;
    }
}
void insert_at_tail(Node *&head, Node *&tail, int val, int &cnt)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        cnt++;
        return;
    }
    else
    {
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        cnt++;
    }
}
void insert_at_any_position(Node *&head, Node *&tail, int pos, int v, int &cnt)
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
    else
    {
        if (pos == 1)
        {
            newNode->next = head;
            head->prev = newNode;
            newNode->prev = NULL;
            head = newNode;
            cnt++;
            return;
        }
        else
        {
            for (int i = 1; i < pos - 1; i++)
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
            newNode->prev = tmp;
            tmp->next = newNode;
            cnt++;
        }
    }
}
void delete_head(Node *&head, Node *tail, int &cnt)
{
    if (head == NULL)
        return;
    Node *deleteNode = head;
    if (head->next == NULL)
    {
        delete deleteNode;
        deleteNode = tail;
        delete deleteNode;
        cnt--;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
        delete deleteNode;
        cnt--;
    }
}
void delete_tail(Node *&head, Node *&tail, int &cnt)
{
    if (tail == NULL)
        return;
    Node *deleteNode = tail;
    if (tail->prev == NULL)
    {
        delete deleteNode;
        deleteNode = head;
        delete deleteNode;
        cnt--;
        return;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
        cnt--;
        delete deleteNode;
    }
}
void delete_at_any_position(Node *&head, Node *&tail, int pos, int &cnt)
{
    Node *tmp = head;
    Node *deleteNode = NULL;
    if (head == NULL)
    {
        return;
    }
    else
    {
        if (pos == 1)
        {
            deleteNode = head;
            if (head->next == NULL)
            {
                delete deleteNode;
                deleteNode = tail;
                delete deleteNode;
                return;
                cnt--;
            }
            else
            {
                head = head->next;
                head->prev = NULL;
                delete deleteNode;
                cnt--;
            }
        }
        else
        {
            for (int i = 1; i < pos - 1; i++)
            {
                if (tmp == NULL || tmp->next == NULL)
                    return;
                tmp = tmp->next;
            }
            if (tmp->next == NULL)
            {
                tail = tmp;
                return;
            }
            deleteNode = tmp->next;
            tmp->next = deleteNode->next;
            if (deleteNode->next != NULL)
                deleteNode->next->prev = tmp;
            else
                tail = tmp;
            delete deleteNode;
            cnt--;
        }
    }
}
void reverse_double_linked_list(Node *&head, Node *&tail, int cnt)
{
    int i, j;
    Node *tmp1 = head;
    Node *tmp2 = tail;
    for (i = 1, j = cnt; i < j; i++, j--)
    {
        swap(tmp1->val, tmp2->val);
        tmp1 = tmp1->next;
        tmp2 = tmp2->prev;
    }
}
void print_forward(Node *tmp)
{
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void print_reverse(Node *tmp)
{
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val, cnt = 0, pos;
    while (true)
    {
        cout << "\nEnter number: ";
        cin >> val;
        if (val < 0)
            break;
        insert_at_tail(head, tail, val, cnt);
    }
    while (true)
    {
        cout << endl;
        cout << "Option 1: Enter any number at head\n";
        cout << "Option 2: Enter any number at tail\n";
        cout << "Option 3: Enter any number at any position\n";
        cout << "Option 4: Delete head\n";
        cout << "Option 5: Delete tail\n";
        cout << "Option 6: Delete any number at any position\n";
        cout << "Option 7: Total Node Count\n";
        cout << "Option 8: Print Forward\n";
        cout << "Option 9: Print reverse\n";
        cout << "Option 10: Reverse node\n";
        cout << "option 11: Terminate\n";

        cout << "\nEnter any option: ";
        int o;
        cin >> o;
        if (o == 1)
        {
            cout << "Enter number: ";
            cin >> val;
            if (val < 0)
                cout << "Invalid number\n";
            else
                insert_at_head(head, tail, val, cnt);
        }
        else if (o == 2)
        {
            cout << "Enter number: ";
            cin >> val;
            if (val < 0)
                cout << "Invalid number\n";
            else
                insert_at_tail(head, tail, val, cnt);
        }

        else if (o == 3)
        {
            cout << "Enter number: ";
            cin >> val;
            cout << "Enter position: ";
            cin >> pos;
            if (val < 0)
                cout << "Invalid number\n";
            else
                insert_at_any_position(head, tail, pos, val, cnt);
        }
        else if (o == 4)
        {
            if (cnt == 0)
                cout << "Head is empty\n";
            else
                delete_head(head, tail, cnt);
        }
        else if (o == 5)
        {
            if (cnt == 0)
                cout << "Tail is empty\n";
            else
                delete_tail(head, tail, cnt);
        }
        else if (o == 6)
        {
            if (cnt == 0)
                cout << "Node is empty\n";
            else
            {
                cout << "Enter position: ";
                cin >> pos;
                delete_at_any_position(head, tail, pos, cnt);
            }
        }
        else if (o == 7)
            cout << "Total Node : " << cnt << endl;
        else if (o == 8)
            print_forward(head);
        else if (o == 9)
            print_reverse(tail);
        else if (o == 10)
            reverse_double_linked_list(head, tail, cnt);
        else if (o == 11)
            break;
        else
            cout << "Invalid option\n";
    }
    return 0;
}