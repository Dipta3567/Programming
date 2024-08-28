/*
Matrix:

1 2 ^ 6 =  e matrix er upur power 6 = 2*2*2*2*2*2 = 64
2 3

binary exponentiation e amra res = 1 dorsi but akane diagonal matrix dorte hobe.

res = Diagonal Matrix:
1 0
0 1

        res       base        power

        R           M           6

        R           M*M         3   // same as binary exponentiation

        R*M         M*M         2

        R*M         M2*M        1  // M2= M*M

        R2*M3        M3         0  // R2 = R*M & M3 = M2*M


*/

#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define N 101
ll mod = 1000000007;
ll arr[N][N], I[N][N]; // I is identity matrix and arr is base matrix

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

                ll x = (A[i][k] * B[k][j]);
                res[i][j] = (res[i][j] + x);

                // ll x=(A[i][k]*B[k][j])%mod;
                // res[i][j]=(res[i][j]+x)%mod;
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
            {
                I[i][j] = 1;
            }
            else
            {
                I[i][j] = 0;
            }
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
    // optimize();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, p, i, j, k;
        //cout << "Enter the size of matrix and power: ";
        cin >> n >> p;

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                cin >> arr[i][j];
            }
        }

        power(arr, n, p);
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}