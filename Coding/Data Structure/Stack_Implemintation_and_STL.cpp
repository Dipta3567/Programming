// ADT = Abstract Data Structure or Higher Level data structure
// Stack use Lifo tecnique = Last In Fast Out
#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
// stack using array
class myStack
{
    public:
    vector<int>v;
    void push(int val)
    {
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v.back();
    }
    int size()
    {
        return v.size();
    }
    bool empty()
    {
        return v.empty();
    }
};
int main()
{
    myStack st;
    int n,i;
    cin >> n;
    for (i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
*/

/*

// stack using list

class myStack
{
    public:
    list<int> l;
    void push(int val)
    {
        l.push_back(val);
    }
    void pop()
    {
        l.pop_back();
    }
    int top()
    {
        return l.back();
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
    myStack st;
    int n,i;
    cin >> n;
    for (i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}

*/


/*

// Singaly linked list


class Stack
{
    //Write your code here

public:
    int cnt=0;
    Node *head=NULL;
    Stack()
    {
        //Write your code here
    }

    int getSize()
    {
        return cnt;
    }

    bool isEmpty()
    {
        if (cnt==0)
        return true;
        else
        return false;
    }

    void push(int data)
    {
        Node *newNode= new Node (data);

        newNode->next=head;
        head=newNode;
        cnt++;

    }

    void pop()
    {
        if (head!=NULL)
        {
            Node *tmp=head;
            head=head->next;
            delete tmp;
            cnt--;
        }

    }

    int getTop()
{
    if (head != NULL)
    {
        return head->data;
    }
    else
    {
        
        return -1;
    }
}

};

*/






/*
// Stack using double linked list

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
class myStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int cnt = 0;
    void push(int val)
    {
        Node *newNode = new Node(val);
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
        Node *del = tail;
        tail = tail->prev;
        if (tail == NULL)
            head = NULL;
        else
            tail->next = NULL;
        delete del;
        cnt--;
    }
    int top()
    {
        return tail->val;
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
    myStack st;
    int n, i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}

*/

// STACK REVERSE USING RECURSION

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;
    int x = st.top();
    st.pop();
    reverseStack(st);
    stack<int> cpy;
    while (!st.empty())
    {
        cpy.push(st.top());
        st.pop();
    }
    cpy.push(x);
    while (!cpy.empty())
    {
        st.push(cpy.top());
        cpy.pop();
    }
}

// STL STACK

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    cout << st.top() << endl;
    if (!st.empty())
        st.pop();
    cout << st.top() << endl;
    if (!st.empty())
        st.pop();
    if (!st.empty())
        st.pop();

    int n, i;
    // cin >> n;
    for (i = 1; i <= 10; i++)
    {
        // int x;
        // cin >> x;
        st.push(5);
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}