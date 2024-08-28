#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Queue implimantation using singaly linked list
/*
class Node
{
    public:
    int val;
    Node *next;
    Node (int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
class myQueue
{
    public:
    Node *head=NULL,*tail=NULL;
    int cnt=0;
    void push(int v)
    {
        Node *newNode = new Node (v);
        if (head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
           tail->next=newNode;
           tail=tail->next;
        }
        cnt++;
    }
    void pop()
    {
        Node *del= head;
        head=head->next;
        delete del;
        if (head==NULL)
        tail=NULL;
        cnt--;
    }
    int front()
    {
        return head->val;
    }
    int size()
    {
        return cnt;
    }
    bool empty()
    {
        if (cnt==0)
        return true;
        else
        return false;

    }
};
int main()
{
    myQueue q;
    int n,i,x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        q.push(x);
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }


    return 0;
}

*/

/*
// Queue implement using double linked list

class Node
{
public:
    int val;
    Node *next, *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class myQueue
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
    void pop()
    {
        Node *del = head;
        head = head->next;
        if (head == NULL)
            tail = NULL;
        else
            head->prev = NULL;
        delete del;

        cnt--;
    }
    int front()
    {
        return head->val;
    }
    int size()
    {
        return cnt;
    }
    bool empty()
    {
        if (cnt == 0)
            return true;
        else
            return false;
    }
};
int main()
{
    myQueue q;
    int n, i, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        q.push(x);
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
*/
/*
// Queue Implement using List

class myQueue
{
public:
    list<int>l;
    void push(int v)
    {
        l.push_back(v);
    }
    void pop()
    {
        l.pop_front();
    }
    int front()
    {
        return l.front();
    }
    int size()
    {
        return l.size();
    }
    bool empty()
    {
        return l.empty();
    }
};
int main()
{
    myQueue q;
    int n, i, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        q.push(x);
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
*/

/*

// Queue using array

#include <bits/stdc++.h>
using namespace std;
#define n 100
class Queue
{
    int arr[n];
    int f = -1, r = -1, sz = 0;

public:
    void push(int x)
    {
        if (f == -1)
        {
            arr[++r] = x;
            sz++;
            f++;
            return;
        }
        if (r + 1 == f || (f == 0 && r == n - 1))
        {
            cout << "Overflow\n";
            return;
        }
        if (r == n - 1)
        {
            r = -1;
        }

        arr[++r] = x;
        sz++;
    }
    void pop()
    {
        if (f == -1)
        {
            cout << "Underflow\n";
            return;
        }
        if (f == r)
        {
            f = r = -1;
        }
        if (f == n - 1)
        {
            f = -1;
        }
        f++;
        sz--;
    }
    void front()
    {
        if (f == -1)
        {
            cout << "Underflow\n";
            return;
        }
        cout << "Value : " << arr[f] << endl;
    }
    int Size()
    {
        return sz;
    }
};
int main()
{
    Queue q;

    while (1)
    {
        cout << "\n1. Push\n2.pop\n3.Front\n4.size\n5.Exit\nChoice : ";
        int x;
        cin >> x;
        if (x == 1)
        {
            int a;
            cout << "Input : ";
            cin >> a;
            q.push(a);
        }
        else if (x == 2)
        {
            q.pop();
        }
        else if (x == 3)
            q.front();
        else if (x == 4)
            cout << "Size : " << q.Size() << endl;
        else if (x == 5 || (x < 0 && x > 5))
            break;
    }
}


*/

// STL Queue

int main()
{
    queue<int> q;
    int n, i, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        q.push(x);
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}


// Reverse Quere
/*
#include <bits/stdc++.h> 
queue<int> reverseQueue(queue<int> &q)
{
    if (q.size()==1)
    return q;
    stack<int>st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    return q;
}


*/
