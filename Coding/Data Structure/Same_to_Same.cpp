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

    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *tmp1 = NULL;
    Node *tmp2 = NULL;
    ll cnt1 = 0, cnt2 = 0;
    while (true)
    {
        ll val;
        cin >> val;
        if (val == -1)
            break;
        else
        {
            cnt1++;
            Node *newNode = new Node(val);
            if (head1 == NULL)
            {

                head1 = newNode;
                tmp1 = head1;
            }
            else
            {
                tmp1->next = newNode;
                tmp1 = tmp1->next;
            }
        }
    }
    while (true)
    {
        ll v;
        cin >> v;
        if (v == -1)
            break;
        else
        {
            cnt2++;
            Node *newNode = new Node(v);
            if (head2 == NULL)
            {

                head2 = newNode;
                tmp2 = head2;
            }
            else
            {
                tmp2->next = newNode;
                tmp2 = tmp2->next;
            }
        }
    }
    tmp1 = head1;
    tmp2 = head2;
    ll flag = 1;
    if (cnt1 == cnt2)
    {
        while (tmp1 != NULL)
        {
            if (tmp1->val != tmp2->val)
            {
                flag = 0;
                break;
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
    else
        flag = 0;
    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}