#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        if (l == -1)
            p->left = NULL;
        else
            p->left = new Node(l);
        if (r == -1)
            p->right = NULL;
        else
            p->right = new Node(r);

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}
int Hight(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
    {
        int l = Hight(root->left);
        int r = Hight(root->right);
        return max(l, r) + 1;
    }
}
void level(Node *root, int x)
{
    queue<pair<Node *, int>> q;
    if (root)
        q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        Node *fir = p.first;
        int level = p.second;
        q.pop();

        if (level == x)
        {
            cout << fir->val << " ";
        }

        if (fir->left)
            q.push({fir->left, level + 1});
        if (fir->right)
            q.push({fir->right, level + 1});
    }
}
int main()
{
    Node *root = input_tree();
    int x;
    cin >> x;
    int h = Hight(root);
    h--;
    if (x < 0 || x > h)
        cout << "Invalid\n";
    else
    {
        level(root, x);
    }
    return 0;
}