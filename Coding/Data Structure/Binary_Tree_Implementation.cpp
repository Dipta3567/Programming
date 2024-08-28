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

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}
void InOrder(Node *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
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

// Function to insert a new value into the BST
Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);
    if (x < root->val)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}


// Binary Tree Input Implementation    // upper code is much easy then this

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

/*

// Write a program to create a Binary Search Tree of n elements and then delete an element from the tree

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* root = NULL;

// Function to insert a new value into the BST
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Function to search a node in the BST
Node* search(int data) {
    Node* ptr = root;
    while (1) {
        if (ptr == NULL)
            return NULL;
        if (data == ptr->data)
            return ptr;
        if (data > ptr->data)
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }
    return NULL;
}

// Function to find the parent of a node in the BST
Node* findParent(Node* res) {
    int data = res->data;
    Node* ptr = root;
    Node* par = NULL;
    while (1) {
        if (data < ptr->data) {
            if (ptr->left == res) {
                par = ptr;
                break;
            }
            ptr = ptr->left;
        } else {
            if (ptr->right == res) {
                par = ptr;
                break;
            }
            ptr = ptr->right;
        }
    }
    return par;
}

// Function to delete a node with one or no children
void deleteOneOrNone(Node* par, Node* res) {
    if (res->left == NULL && res->right == NULL) {
        if (par->left == res)
            par->left = NULL;
        else
            par->right = NULL;
        delete res;
    } else if (res->left == NULL || res->right == NULL) {
        if (res->left != NULL) {
            if (par->left == res)
                par->left = res->left;
            else
                par->right = res->left;
        } else {
            if (par->left == res)
                par->left = res->right;
            else
                par->right = res->right;
        }
        delete res;
    }
}

// Function to delete a node from the BST
void Delete(int data) {
    Node* res = search(data);
    if (res == NULL) {
        cout << "Not Found\n";
        return;
    }

    if (res == root) {
        if (root->left != NULL && root->right != NULL) {
            Node* temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            int data = temp->data;
            Node* par = findParent(temp);
            deleteOneOrNone(par, temp);
            root->data = data;
        } else if (root->left == NULL && root->right == NULL) {
            root = NULL;
        } else if (root->left != NULL) {
            root = root->left;
        } else if (root->right != NULL) {
            root = root->right;
        }
        return;
    }

    Node* par = findParent(res);
    if (res->left == NULL || res->right == NULL) {
        deleteOneOrNone(par, res);
        return;
    }
    Node* temp = res->right;
    while (temp->left != NULL)
        temp = temp->left;
    res->data = temp->data;
    par = findParent(temp);
    deleteOneOrNone(par, temp);
}

// Function to print the tree in level order
void printLevelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        cout << node->data << " ";

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    cout << "\n";
}

int main() {
    int n, x, deleteElement;

    cout << "Enter the number of elements:\n";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Tree in level order before deletion:\n";
    printLevelOrder(root);

    cout << "Enter the element to delete:\n";
    cin >> deleteElement;

    Delete(deleteElement);

    cout << "Tree in level order after deletion:\n";
    printLevelOrder(root);

    return 0;
}



*/





void count(Node *root, int &cnt)
{
    if (root == NULL)
        return;
    cnt++;
    count(root->left, cnt);
    count(root->right, cnt);
}

// Leaf Node Count

int count_leaf(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
    {
        int l = count_leaf(root->left);
        int r = count_leaf(root->right);
        return l + r;
    }
}

// Find a value in which level it is , root level = 1. used pair for this problem

int nodeLevel(Node *root, int v)
{
    queue<pair<Node *, int>> q;
    q.push({root, 1});

    while (!q.empty())
    {
        pair<Node *, int> parent = q.front();
        Node *node = parent.first;
        int level = parent.second;
        q.pop();

        if (node->val == v)
            return level;

        if (node->left)
        {
            q.push({node->left, level + 1});
        }
        if (node->right)
        {
            q.push({node->right, level + 1});
        }
    }
    return 0;
}

// Left view Of a binary tree : https://www.codingninjas.com/studio/problems/left-view-of-a-binary-tree_920519
// it means every one node which is in left of every level
// print_outer_tree.cpp
vector<int> get_Left_view(Node *root)
{
    vector<int> v;
    if (root == NULL)
        return v;
    bool freq[3005] = {false};

    queue<pair<Node *, int>> q;

    q.push({root, 1});

    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();
        Node *tmp = p.first;
        int level = p.second;

        if (freq[level] == false)
        {
            v.push_back(tmp->val);
            freq[level] = true;
        }

        if (tmp->left)
            q.push({tmp->left, level + 1});
        if (tmp->right)
            q.push({tmp->right, level + 1});
    }
    return v;
}

// Maximum Hight

int max_hight(Node *root)
{
    if (root == NULL)
        return 0;
    int l = max_hight(root->left);
    int r = max_hight(root->right);
    return max(l, r) + 1;
}

// Diameter Of Binary Tree : https://www.codingninjas.com/studio/problems/diameter-of-the-binary-tree_920552
int mx = 0;
int max_hight_1(Node *root)
{
    if (root == NULL)
        return 0;
    int l = max_hight_1(root->left);
    int r = max_hight_1(root->right);
    int d = l + r;
    mx = max(mx, d);
    return max(l, r) + 1;
}
int diameter(Node *root)
{
    mx = 0;
    int h = max_hight_1(root);
    return mx;
}

// Same Tree : https://leetcode.com/problems/same-tree/description/

/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/

bool isSameTree(Node *p, Node *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// or another soluation

bool ans = true;
void same_Tree(Node *p, Node *q)
{
    if (p == NULL && q == NULL)
    {
        return;
    }
    if (ans == false)
    {
        return;
    }
    if (p == NULL && q != NULL || p != NULL && q == NULL)
    {
        ans = false;
        return;
    }
    if (p != NULL && q != NULL && p->val != q->val)
    {
        ans = false;
        return;
    }
    same_Tree(p->left, q->left);

    same_Tree(p->right, q->right);
}
bool is_Same_Tree(Node *p, Node *q)
{

    same_Tree(p, q);
    return ans;
}

// Binary Tree Tilt : https://leetcode.com/problems/binary-tree-tilt/description/

/*
Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.
*/

int tilt;
int post(Node *root)
{
    if (root == NULL)
        return 0;
    int left = post(root->left);
    int right = post(root->right);
    tilt += abs(left - right);
    return left + right + root->val;
}
int findTilt(Node *root)
{
    tilt = 0;
    post(root);
    return tilt;
}



////// Write a program to create a Binary Search Tree of n elements and then delete an element from the tree

// Function to insert a new value into the BST
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Function to find the minimum value node in a subtree
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a value from the BST
Node* deleteNode(Node* root, int val) {
    if (root == NULL)
        return root;
    if (val < root->val)
        root = deleteNode(root->left, val);
    else if (val > root->val)
        root = deleteNode(root->right, val);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, x, deleteElement;

    cout << "Enter the number of elements:\n";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Inorder traversal of the tree:\n";
    inorder(root);
    cout << "\n";

    cout << "Enter the element to delete:\n";
    cin >> deleteElement;

    root = deleteNode(root, deleteElement);

    cout << "Inorder traversal after deletion:\n";
    inorder(root);
    cout << "\n";

    return 0;
}



int main()
{
    /*
    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);
    Node *f = new Node(70);
    Node *g = new Node(80);
    Node *h = new Node(90);
    Node *i = new Node(100);

    // connection

    root->left = a;
    root->right = b;
    a->left = c;
    a->right = h;
    c->right = e;
    h->right = i;
    b->right = d;
    d->left = f;
    d->right = g;
*/

    // Input Implementation (Easy way)
    int n, x;
    Node *root = NULL;
    cout << "Enter the number of elements:\n";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
    }


    // Binary Tree Input Implementation

    Node *root = input_tree(); // input example : 10 20 30 -1 40 50 60 -1 -1 70 -1 -1 80 -1 -1 90 100 -1 -1 -1 1000 -1 -1
    cout << endl
         << endl;

    int cnt = 0;
    count(root, cnt);
    cout << "Node : " << cnt << endl;
    cout << "Leaf : " << count_leaf(root) << endl;
    cout << "Maximum Hight : " << max_hight(root) << endl
         << endl
         << "Level Order : ";

    Level_Order(root);

    /*
    print order :
    1. Depth :
        a: pre order -> root , left, right
        b: post order -> left, right, root
        c: In order -> left, root , right

    2.Level

    */

    /*
     // PreOrder print
     preOrder(root);
     cout << endl;

     // PostOrder print
     postOrder(root);
     cout << endl;

     // InOrder print
     InOrder(root);
     cout << endl;

     // Level Order print
     Level_Order(root);
     cout << endl;

 */

    return 0;
}