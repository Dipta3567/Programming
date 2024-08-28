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
    Node *head = NULL;
    Node *tmp = NULL;
    ll max = 0, min = 0, f = 0;
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
                max = min = val;
                head = newNode;
                tmp = head;
            }
            else
            {
                tmp->next = newNode;
                tmp = tmp->next;
            }
            if (val > max)
                max = val;
            if (val < min)
                min = val;
        }
    }
    cout << max - min << endl;
    return 0;
}