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
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = NULL;
        Node *tmp = NULL;
        while (true)
        {
            ll val;
            cin >> val;
            if (val == -1)
                break;
            else
            {
                Node *newNode = new Node(val);
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
        }
        int x, pos = -1, f = 0;
        cin >> x;
        tmp = head;
        while (tmp != NULL)
        {
            pos++;
            if (tmp->val == x)
            {
                f = 1;
                break;
            }
            tmp=tmp->next;
        }
        if (f == 1)
            cout << pos << endl;
        else
            cout << "-1\n";
    }
    return 0;
}