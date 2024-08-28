#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n, e, i, j, k;
    cin >> n >> e;
    ll adj[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = INT_MAX;
        }
    }
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c; // if there are multiple edge then : adj[a][b]=min(adj[a][b],c);
    }
    cout << endl
         << endl;
    cout << "BEFORE\n\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (adj[i][j] == INT_MAX)
                cout << "INF"
                     << " ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ((adj[i][k] + adj[k][j]) < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    // print

    cout << endl
         << endl;
    cout << "After\n\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (adj[i][j] == INT_MAX)
                cout << "INF"
                     << " ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    // cycle detect

    for (i = 0; i < n; i++)
    {
        if (adj[i][i] < 0)
        {
            cout << "Cycle Detected\n";
            break;
        }
    }
    return 0;
}

/*
input:

4 6
3 2 8
2 1 5
1 0 2
3 0 20
0 1 3
1 2 2
*/