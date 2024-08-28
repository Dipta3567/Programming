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
vector<int> v;
void leaf(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        v.push_back(root->val);
    leaf(root->left);
    leaf(root->right);
}

int main()
{
    Node *root = input_tree();
    v.clear();
    if (root == NULL)
        cout << "0\n";
    else
    {
        leaf(root);
        sort(v.begin(), v.end(), greater<int>());
        for (auto u : v)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}