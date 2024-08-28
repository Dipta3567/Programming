#include <bits/stdc++.h>
using namespace std;
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
    Node *newNode = new Node(v);
    Node *tmp = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}
void print_Node(Node *head)
{
    Node *tmp = head;
    //cout << "The Linked List: ";
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void count(Node *head)
{
    int cnt = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }
    cout << "Total count: " << cnt << endl;
}
void duplicate_check(Node *&head)
{
    Node *tmp = head;
    int freq[100] = {0};
    while (tmp != NULL)
    {
        freq[tmp->val]++;
        tmp = tmp->next;
    }
    int f = 0;
    for (int i = 0; i < 100; i++)
    {
        if (freq[i] > 1)
        {
            f = 1;
            break;
        }
    }
    if (f == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}
void middle_element(Node *head)
{
    int cnt = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }
    tmp = head;
    int i;
    double f;
    if (cnt % 2 == 0)
    {
        f = cnt / 2;
        cout << "\nElement: ";
        for (i = 0; i < cnt; i++)
        {
            if (i == f || i == f - 1)
            {
                cout << tmp->val << " ";
            }
            tmp = tmp->next;
        }
        cout << endl;
    }
    else
    {
        f = cnt / 2;
        for (i = 0; i < cnt; i++)
        {
            if (i == f)
            {
                cout << "\nElement: " << tmp->val << " ";
                break;
            }
            tmp = tmp->next;
        }
        cout << endl;
    }
}
void insert_at_head(Node *&head,int val)
{
    Node*newNode=new Node(val);
    newNode->next=head;
    head=newNode;
}
int insert_at_pos(Node *&head,int pos,int val)
{
    Node*tmp=head;
    Node *newNode=new Node(val);
    if (pos==0)
    insert_at_head(head,val);
    else
    {
         
        for (int i=1;i<pos;i++)
        {
            if (tmp == NULL || tmp->next == NULL)
            {
                cout << "Invalid\n";
                return 2;
            }
            else
            tmp=tmp->next;
        }
        newNode->next=tmp->next;
        tmp->next=newNode;
    }
    return 1;

}
void sorted(Node *head)
{
    Node*tmp=head;
    Node*tmp1=head;
    tmp1=tmp->next;
    int f=0;
    while (tmp1!=NULL)
    {
        if (tmp1->val<(tmp->val))
        {
            f=1;
            break;
        }
        tmp=tmp->next;
        tmp1=tmp1->next;
    }
    if (f==1)
    cout << "NO\n";
    else
    cout << "YES\n";
}

int main()
{
    int val, op;
    Node *head = NULL;

    while (true)
    {
        //cout << "Enter the value: ";
        cin >> val;
        if (val < 0)
            break;
        insert_at_tail(head, val);
    }
  
  // Ques 5

  sorted(head);


    //Ques-4


    /*int t,index,value;
    cin >> t;
    while (t--)
    {
        cin >> index >> value;
        int f =insert_at_pos(head,index,value);
        if (f!=2)
        print_Node(head);
    }*/
    
    // Ques 1,2,3

    /*while (1)
    {
        cout << "\nOption 1: Insert at tail\n";
        cout << "Option 2: Print List\n";
        cout << "Option 3: Count Node\n";
        cout << "Option 4: Duplicate\n";
        cout << "Option 5: Middle Element\n";
        cout << "Option 6: Terminate\n";
        cout << "Enter option: ";
        cin >> op;
        if (op == 1)
        {
            cout << "Enter the value: ";
            cin >> val;
            insert_at_tail(head, val);
        }
        else if (op == 2)
        {
            print_Node(head);
        }
        else if (op == 3)
        {
            count(head);
        }
        else if (op == 4)
        {
            duplicate_check(head);
        }
        else if (op == 5)
        {
            middle_element(head);
        }
        else if (op == 6)
            break;
    }*/
    return 0;
}
