#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class CircularHeaderLinkedList {
public:
    Node *header;
    
    CircularHeaderLinkedList() {
        header = new Node(0); // Create header node
        header->next = header; // Initialize to point to itself
    }

    void insert(int v) {
        Node *newNode = new Node(v);
        Node *tmp = header;
        
        while (tmp->next != header) {
            tmp = tmp->next;
        }
        
        tmp->next = newNode;
        newNode->next = header;
    }

    void display() {
        if (header->next == header) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node *tmp = header->next;
        
        while (tmp != header) {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        
        cout << endl;
    }
};

int main() {
    CircularHeaderLinkedList list;
    int n, value;

    cout << "Enter the number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        list.insert(value);
    }
    list.display();
    return 0;
}
