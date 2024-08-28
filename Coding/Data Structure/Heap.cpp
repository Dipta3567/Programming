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
/*
HEAP : Complete Binary Tree er Array Representation
    BST hobe na ( Duplicate value thakte parbe)

Max Heap:

    array er highest value ber kore dibe

    e node  er child node (left and right) theke boro hobe or equal

Min Heap:
    array er lowest value ber kore dibe
    e node  er child node (left and right) theke choto hobe or equal
*/
#include<bits/stdc++.h>
using namespace std;

// Insert in Heap Implementation

void insert_Max_Heap(vector<int> &v, int x)
{
    v.push_back(x);
    int cur_idx = v.size() - 1;
    while (cur_idx != 0)
    {
        int parent_idx = (cur_idx - 1) / 2;

        // Insert at MAX HEAP
        if (v[parent_idx] < v[cur_idx])
            swap(v[parent_idx], v[cur_idx]);
        else
            break;
        cur_idx = parent_idx;
    }
}
void insert_Min_Heap(vector<int> &v, int x)
{
    v.push_back(x);
    int cur_idx = v.size() - 1;
    while (cur_idx != 0)
    {
        int parent_idx = (cur_idx - 1) / 2;

        // Insert at Min HEAP
        if (v[parent_idx] > v[cur_idx])
            swap(v[parent_idx], v[cur_idx]);
        else
            break;
        cur_idx = parent_idx;
    }
}
void delete_Max_heap(vector<int> &v) // Delete max heap // Its a big code, easy one is after this
{
    v[0] = v[v.size() - 1];
    v.pop_back();
    int cur = 0;
    while (true)
    {
        int left = (cur * 2) + 1;
        int right = (cur * 2) + 2;
        int last = v.size() - 1;
        if (left <= last && right <= last)
        {
            if (v[left] >= v[right] && v[left] > v[cur])
            {
                swap(v[left], v[cur]);
                cur = left;
            }
            else if (v[right] >= v[left] && v[right] > v[cur])
            {
                swap(v[right], v[cur]);
                cur = right;
            }
            else
            {
                break;
            }
        }
        else if (left <= last)
        {
            if (v[left] > v[cur])
            {
                swap(v[left], v[cur]);
                cur = left;
            }
            else
            {
                break;
            }
        }
        else if (right <= last)
        {
            if (v[right] > v[cur])
            {
                swap(v[right], v[cur]);
                cur = right;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}
void delete_Max_Heap(vector<int> &v) // Its easy one
{
    if (v.empty())
        return;
    v[0] = v.back();
    v.pop_back();
    int cur = 0;
    while (true)
    {
        int left = (cur * 2) + 1;
        int right = (cur * 2) + 2;
        int last = v.size() - 1;
        int largest = cur;

        if (left <= last && v[left] > v[largest])
            largest = left;
        if (right <= last && v[right] > v[largest])
            largest = right;
        if (largest != cur)
        {
            swap(v[cur], v[largest]);
            cur = largest;
        }
        else
        {
            break;
        }
    }
}
void delete_Min_heap(vector<int> &v)
{
    v[0] = v[v.size() - 1];
    v.pop_back();
    int cur = 0;
    while (true)
    {
        int left = (cur * 2) + 1;
        int right = (cur * 2) + 2;
        int last = v.size() - 1;
        if (left <= last && right <= last)
        {
            if (v[left] <= v[right] && v[left] < v[cur])
            {
                swap(v[left], v[cur]);
                cur = left;
            }
            else if (v[right] <= v[left] && v[right] < v[cur])
            {
                swap(v[right], v[cur]);
                cur = right;
            }
            else
            {
                break;
            }
        }
        else if (left <= last)
        {
            if (v[left] < v[cur])
            {
                swap(v[left], v[cur]);
                cur = left;
            }
            else
            {
                break;
            }
        }
        else if (right <= last)
        {
            if (v[right] < v[cur])
            {
                swap(v[right], v[cur]);
                cur = right;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}

void print_heap(vector<int> v)
{
    for (auto u : v)
        cout << u << " ";
    cout << endl
         << endl;
}

int main()
{
    
    
    
    /*
    int n, i, x;
    cin >> n;
    vector<int> v;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert_Min_Heap(v, x);
    }
    cout << endl;
    print_heap(v);
    delete_Min_heap(v);
    print_heap(v);
    delete_Min_heap(v);
    print_heap(v);
    */
    return 0;
}

/*

 Write a program to sort n numbers using Heap sort algorithm.



 #include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(vector<int> &arr, int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Utility function to print the array
void printArray(const vector<int> &arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    cout << "Sorted array is: ";
    printArray(arr);

    return 0;
}


*/