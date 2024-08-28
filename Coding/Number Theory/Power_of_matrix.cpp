#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define N 101
ll mod = 1000000007;
ll arr[N][N], I[N][N];

void multiply(ll A[][N], ll B[][N], ll n)
{
    ll i, j, k;
    ll res[n + 1][n + 1];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            res[i][j] = 0;
            for (k = 1; k <= n; k++)
            {
                ll x = (A[i][k] * B[k][j]) % mod;
                res[i][j] = (res[i][j] + x) % mod;
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            A[i][j] = res[i][j];
        }
    }
}

void power(ll A[][N], ll n, ll p)
{
    ll i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

    while (p)
    {
        if (p % 2 == 1)
        {
            multiply(I, A, n);
            p--;
        }
        else
        {
            multiply(A, A, n);
            p /= 2;
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            A[i][j] = I[i][j];
        }
    }
}

int main()
{
    optimize();
    ll t, i, j, n, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
                cin >> arr[i][j];
        }

        power(arr, n, p);

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}