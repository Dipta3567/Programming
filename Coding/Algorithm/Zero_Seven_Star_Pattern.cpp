#include <bits/stdc++.h>
using namespace std;

void printPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || i + j == n - 1)
                cout << "*";
            else if (i < j && i + j < n - 1)
                cout << "0";
            else if (i > j && i + j > n - 1)
                cout << "0";
            else
                cout << "7";
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    printPattern(n);
    return 0;
}