/*
BST = Binary Search Tree = Binary Tree + Binary search

Condition:
1. node left < node

2. node right >node

3. same value can not be add

*/

/*
akta tree ke level order e akta array te neyar por kon akta value er left and right node e ki asilo jante cayle

    Condition:
        Tree have to be Complete Binary tree

    Usage:
        For Parent to child

    Formula:
        1. Left Node = Index*2+1
        2. Right Node = Index*2+2

    Usage:
        For child to Parent

    Formula:
        For both left and right node : (Index-1)/2

*/



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
Node *input_tree() // hard // easy function is under this one
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
        // 1. value ber kore ana
        Node *p = q.front();
        q.pop();

        // 2. jabotiyo kaj kora
        int l, r;
        cin >> l >> r;
        Node *myLeft, *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        // 3. childer push kora
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}
Node *insert(Node *root, int val) 

{ 

    if (root == NULL) 

        return new Node(val); 

    if (val < root->val) 

        root->left = insert(root->left, val); 

    else 

        root->right = insert(root->right, val); 

    return root; 

} 
void Level_Order(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        // 1. Value ber kore ana
        Node *f = q.front();
        q.pop();

        // 2. Ja ja kaj ase ogula kora
        cout << f->val << " ";

        //  3. children Node ke raka
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);

        /*
        jodi amr right side theke left side er value lage tahole
            if (f->right)
                q.push(f->right);
            if (f->left)
                q.push(f->left);

        */
    }
}

// Search in BST

bool search(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->val == x)
        return true;
    if (x < root->val)
    {
        return search(root->left, x);
    }
    else
        return search(root->right, x);
}

// Insert in BST

void insert_at_BST(Node *&root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
        return;
    }
    if (x < root->val)
    {
        if (root->left == NULL)
        {
            root->left = new Node(x);
        }
        else
        {
            insert_at_BST(root->left, x);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new Node(x);
        }
        else
        {
            insert_at_BST(root->right, x);
        }
    }
}

// Convert array to BST  // Condition : Array have to be Sorted
Node *convert(int arr[], int n, int l, int r)
{
    if (l > r)
        return NULL;

    int mid = (l + r) / 2;
    Node *root = new Node(arr[mid]);
    Node *left_Node = convert(arr, n, l, mid - 1);
    Node *right_Node = convert(arr, n, mid + 1, r);
    root->left = left_Node;
    root->right = right_Node;
    return root;
}


// Copy a Subtree : https://leetcode.com/problems/search-in-a-binary-search-tree/

Node *cpy;
Node *level(Node *org)
{
    if (org == NULL)
        return NULL;
    Node *root = new Node(org->val);
    root->left = level(org->left);
    root->right = level(org->right);
    return root;
}
void pre(Node *root, int v)
{
    if (root == NULL)
        return;
    if (root->val == v)
    {
        cpy = level(root);
    }
    pre(root->left, v);
    pre(root->right, v);
}
Node *searchBST(Node *r, int val)
{
    cpy = NULL;
    pre(r, val);
    return cpy;
}



// Increasing Order Search Tree : https://leetcode.com/problems/increasing-order-search-tree/description/

vector<int> v;
void pre(Node *root)
{
    if (root == NULL)
        return;
    v.push_back(root->val);
    pre(root->left);
    pre(root->right);
}
Node *increasingBST(Node *r)
{
    v.clear();
    pre(r);
    sort(v.begin(), v.end());
    Node *root = new Node(0);
    Node *cur = root;
    for (int i = 0; i < v.size(); i++)
    {

        cur->right = new Node(v[i]);
        cur = cur->right;
    }
    return root->right;
}

// check subtree are in main tree : https://leetcode.com/problems/subtree-of-another-tree/

bool areIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    return (root1->val == root2->val &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right));
}

bool isSubtree(Node *root, Node *subRoot)
{
    if (subRoot == NULL)
        return true;
    if (root == NULL)
        return false;
    if (areIdentical(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{

    

    /*
    // Convert array to BST
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    Node *root = convert(arr, n, 0, n - 1);
    Level_Order(root);
    */
    /*
    Node *root = input_tree();  // 20 10 30 -1 15 25 35 -1 -1 -1 -1 -1 -1

    insert_at_BST(root,13);
    insert_at_BST(root,32);
    insert_at_BST(root,27);
    insert_at_BST(root,22);
    Level_Order(root);

    */
    /*
    if (search(root, 15))
        cout << "Found\n";
    else
        cout << "NOT FOUND\n";

    */

    return 0;
}