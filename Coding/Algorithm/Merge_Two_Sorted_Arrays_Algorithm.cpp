// Merge Two Sorted Arrays Implementation

#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int m, int r)
{
    int left = m - l + 1;
    int right = r - m;
    int L[left], R[right];
    int k = 0;
    for (int i = l; i <= m; i++)
    {
        L[k] = a[i];
        k++;
    }
    k = 0;
    for (int i = m + 1; i <= r; i++)
    {
        R[k] = a[i];
        k++;
    }
    int i = 0, j = 0;
    int cur = l;
    while (i < left && j < right)
    {
        if (L[i] <= R[j])
        {
            a[cur] = L[i];
            i++;
        }
        else
        {
            a[cur] = R[j];
            j++;
        }
        cur++;
    }
    while (i < left)
    {
        a[cur] = L[i];
        i++;
        cur++;
    }
    while (j < right)
    {
        a[cur] = R[j];
        j++;
        cur++;
    }
}

void divide(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
        cout << a[i] << " ";
    cout << endl;
    if (l < r)
    {
        int mid = (l + r) / 2;
        divide(a, l, mid);
        divide(a, mid + 1, r);
    }
}
void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}
int main()
{
    int n, i, j;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    // merge(a, 0, 3, n - 1); // ata jodi 2 tai sorted hoi tahole and index jana thakle

    // Divide in Merge Sort

    // divide(a, 0, n - 1);

    // Merge Sort

    merge_sort(a, 0, n - 1);

    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

/*
input:
10
2 3 5 10 1 4 6 8 9 15

*/
