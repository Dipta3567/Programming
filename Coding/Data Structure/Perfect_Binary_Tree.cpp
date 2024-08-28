#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int val;
    Node *left;
    Node *right;
    Node (int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
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
        Node *p=q.front();
        q.pop();


        int l, r;
        cin >> l >> r;
        if (l==-1)
        p->left=NULL;
        else
        p->left=new Node (l);
        if (r==-1)
        p->right=NULL;
        else
        p->right=new Node (r);

        if (p->left)
        q.push(p->left);
        if (p->right)
        q.push(p->right);

    }
    return root;
}
int f;
void level(Node *root)
{
    queue<Node*>q;
    if (root)
    q.push(root);
    while (!q.empty())
    {
        Node *p=q.front();
        q.pop();

        if ((p->left==NULL && p->right!=NULL) || (p->left!=NULL && p->right==NULL))
        f=0;

        if (p->left)
        q.push(p->left);
        if (p->right)
        q.push(p->right);

    }
}
int main()
{
    f=1;
    Node *root=input_tree();
    if (root==NULL)
    cout << "YES\n";
    else
    {
        level(root);
        if (f)
        cout << "YES\n";
        else
        cout << "NO\n";
    }
    return 0;
}