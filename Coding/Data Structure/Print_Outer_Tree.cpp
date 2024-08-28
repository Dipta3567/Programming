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
int f = 0;
void get_left(Node *root)
{
    if (root == NULL)
        return;
    if (root->left)
        get_left(root->left);
    else if (root->right)
        get_left(root->right);
    cout << root->val << " ";
}
void get_right(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    if (root->right)
        get_right(root->right);
    else if (root->left)
        get_right(root->left);
}
int main()
{
    Node *root = input_tree();
    int f = 0;
    if (root->left == NULL && root->right == NULL)
        cout << root->val << endl;
    else if (root->left != NULL && root->right == NULL)
    {

        get_left(root);
    }
    else if (root->left == NULL && root->right != NULL)
    {

        get_right(root);
    }
    else if (root->left != NULL && root->right != NULL)
    {
        get_left(root->left);
        get_right(root);
    }
    return 0;
}

/*

আপনি মডিউলে দেখানো টেকনিক ইউজ করে লেভেল অরডারে ইনপুট নিয়ে নিতে পারেন।
এরপর,
root এর left আছে কিনা যদি থাকে তাহলে  printLeft (আপনি যেকোনো নাম দিতে পারেন) নামের একটি function call করবো  এবং সেইখানে root কে পাঠিয়ে দিব।
এখন root এর মানটি প্রিন্ট করবো
root এর right আছে কিনা যদি থাকে তাহলে  printRight (আপনি যেকোনো নাম দিতে পারেন) নামের একটি function call করবো  এবং সেইখানে root কে পাঠিয়ে দিব।

এখন আসি printLeft function টিতে কি করবো.
প্রথমে চেক করবো root এর left আছে কিনা,  যদি থাকে তাহলে printfLeft কে  recursive call করবো এবং recursive কলের সময় argument হিসেবে root এর left কে পাঠাবো। এরপর root এর left এর মানটি প্রিন্ট করে দিব।
যদি root এর left না থাকে তাহলে চেক করবেন  root এর right আছে কিনা, যদি থাকে তাহলে printLeft কে  recursive call করবো এবং recursive কলের সময় argument হিসেবে root এর right কে পাঠাবো। এরপর root এর right এর মানটি প্রিন্ট করে দিব।

এখন আসি printRight function টিতে কি করবো.
প্রথমে চেক করবো root এর right আছে কিনা,  যদি থাকে তাহলে root এর right  এর মানটি প্রিন্ট করে দিব। এরপর printRight কে  recursive call করবো এবং recursive কলের সময় argument হিসেবে root এর right কে পাঠাবো।
যদি root এর right না থাকে তাহলে চেক করবেন  root এর left আছে কিনা,  যদি থাকে তাহলে root এর left এর মানটি প্রিন্ট করে দিব। এরপর printRight কে  recursive call করবো এবং recursive কলের সময় argument হিসেবে root এর left কে পাঠাবো।







*/