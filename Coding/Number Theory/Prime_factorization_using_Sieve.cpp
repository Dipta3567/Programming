#include <bits/stdc++.h>
using namespace std;

int arr[1000001];

void sieve()
{
    int maxN = 1000000;
    for (int i=1;i<=maxN;i++)
    {
        arr[i] = -1;
    }
    for (int i=2;i<=maxN;i++)
    {
        if (arr[i] == -1)
        {
            for (int j=i;j<=maxN;j+=i)
            {
                if (arr[j] == -1)
                {
                    arr[j] = i;
                }
            }
        }
    }
}
int main()
{
    sieve();
    int n;
    cin >> n;
    while (n != 1)
    {
        cout << arr[n] << " ";
        n = n / arr[n];
    }
    return 0;
}