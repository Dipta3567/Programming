#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
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
    Node *tmp = head;
    Node *newNode = new Node(v);
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
int count(Node *tmp)
{
    int f = 0;
    while (tmp != NULL)
    {
        f++;
        tmp = tmp->next;
    }
    return f;
}
void print_reverse_recursion(Node *tmp)
{
    if (tmp == NULL)
        return;
    print_reverse_recursion(tmp->next);
    cout << tmp->val << " ";
}
void maxi(Node *tmp)
{
    int x = 0;
    while (tmp != NULL)
    {
        if (tmp->val > x)
            x = tmp->val;
        tmp = tmp->next;
    }
    cout << x << endl;
}
void desending_sort(Node *head)
{
    Node *tmp = head;
    int x = 0;
    while (tmp != NULL)
    {
        if (tmp->val > x)
            x = tmp->val;
        tmp = tmp->next;
    }
    tmp = head;
    vector<long long int> freq(x+1, 0);
    while (tmp != NULL)
    {
        freq[tmp->val]++;
        tmp = tmp->next;
    }
    for (int i = x; i >= 0; i--)
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
    optimize();
    Node *head1 = NULL;
    Node *head2 = NULL;
    while (true)
    {
        int v;
        cin >> v;
        if (v < 0)
            break;
        insert_at_tail(head1, v);
    }
    desending_sort(head1);
    // maxi(head1);
    // print_reverse_recursion(head1);
    // cout << endl;
    /*
    while (true)
    {
        int v;
        cin >> v;
        if (v < 0)
            break;
        insert_at_tail(head2, v);
    }
    int cnt1 = 0, cnt2 = 0;
    cnt1 = count(head1);
    cnt2 = count(head2);
    if (cnt1 == cnt2)
        cout << "YES\n";
    else
        cout << "NO\n";
*/
    return 0;
}