#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll i, j, k, n, x;
    cin >> n;
    ll v[n][n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> x;
            v[i][j] = x;
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ((v[i][k] + v[k][j]) < v[i][j])
                    v[i][j] = v[i][k] + v[k][j];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}