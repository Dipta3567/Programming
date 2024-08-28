#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n, e, i, t, x, y, j, a, b, c, k;
    cin >> n >> e;
    ll v[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                v[i][j] = 0;
            else
                v[i][j] = 1e18;
        }
    }
    while (e--)
    {
        cin >> a >> b >> c;
        v[a-1][b-1] = min(v[a-1][b-1], c);
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (v[i][k] + v[k][j] < v[i][j])
                    v[i][j] = v[i][k] + v[k][j];
            }
        }
    }
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        if (v[x-1][y-1] == 1e18)
            cout << "-1\n";
        else
            cout << v[x-1][y-1] << endl;
    }

    return 0;
}