#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    int priority;
    Node *next;

    Node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
        this->next = NULL;
    }
};

class PriorityQueue
{
    Node *head;

public:
    PriorityQueue() : head(NULL) {}

    // Function to insert according to priority
    void push(int data, int priority)
    {
        Node *newNode = new Node(data, priority);

        // Special case: The head of list has lesser priority
        if (head == NULL || priority > head->priority)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            // Locate the node before the point of insertion
            Node *tmp = head;
            while (tmp->next != NULL && tmp->next->priority > priority)
            {
                tmp = tmp->next;
            }

            newNode->next = tmp->next;
            tmp->next = newNode;
        }
    }

    // Function to delete the element with the highest priority
    void pop()
    {
        if (head == NULL)
        {
            cout << "Underflow\n";
            return;
        }

        Node *tmp = head;
        head = head->next;
        delete tmp;
    }

    // Function to display the elements in the priority queue
    void display()
    {
        Node *tmp = head;
        while (tmp != NULL)
        {
            cout << "Data: " << tmp->data << ", Priority: " << tmp->priority << endl;
            tmp = tmp->next;
        }
    }
};

int main()
{
    PriorityQueue pq;
    pq.push(2, 1);
    pq.push(3, 2);
    pq.push(1, 3);
    pq.display();
    pq.pop();
    pq.display();
    return 0;
}
