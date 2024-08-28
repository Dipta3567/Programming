#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll INF = 1e18;
int main()
{
    ll i, j, k, n, x;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(n));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> x;
            if (x == -1)
                v[i][j] = INF;
            else
                v[i][j] = x;
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (v[i][k] < INF && v[k][j] < INF && (v[i][k] + v[k][j]) < v[i][j])
                    v[i][j] = v[i][k] + v[k][j];
            }
        }
    }
    x = -1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i][j] != INF && v[i][j] > x)
                x = v[i][j];
        }
    }
    cout << x << endl;
    return 0;
}
