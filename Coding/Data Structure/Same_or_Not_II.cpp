#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class mystack
{
public:
    Node *head = NULL, *tail = NULL;
    int cnt = 0;
    void push(int v)
    {
        Node *newNode = new Node(v);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = tail->next;
        }
        cnt++;
    }
    bool size()
    {
        if (cnt == 0)
            return true;
        else
            return false;
    }
    void pop()
    {
        Node *tmp = tail;
        tail=tail->prev;
        if (tail == NULL)
        {
            head=NULL;
        }
        else
            tail->next=NULL;
        delete tmp;
        cnt--;
    }
    int top()
    {
        return tail->val;
    }
};
class myqueue
{
public:
    Node *head=NULL, *tail=NULL;
    int cnt = 0;
    void push(int v)
    {
        Node *newNode = new Node(v);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = tail->next;
        }
        cnt++;
    }
    bool size()
    {
        if (cnt == 0)
            return true;
        else
            return false;
    }
    int front()
    {
        return head->val;
    }
    void pop()
    {
        Node *tmp = head;
        head=head->next;
        if (head == NULL)
        {
            tail=NULL;
        }
        else
            head->prev=NULL;
        delete tmp;
        cnt--;
    }
};
int main()
{
    mystack st;
    myqueue q;
    int n, m, i, x, f = 1;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        st.push(x);
    }
    for (i = 1; i <= m; i++)
    {
        cin >> x;
        q.push(x);
    }
    if (n != m)
        f = 0;
    else
    {
        while (!st.size())
        {
            if (st.top() != q.front())
            {
                f = 0;
                break;
            }
            st.pop();
            q.pop();
        }
    }
    if (f == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}