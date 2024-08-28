#include <bits/stdc++.h>
using namespace std;
vector<int> v[1010];

int main()
{
    int n, e, a, b, t, i, f;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
    }
    cin >> t;
    while (t--)
    {
        f = 0;
        cin >> a >> b;
        if (a == b)
            cout << "YES\n";
        else
        {
            for (auto u : v[a])
            {
                if (u == b)
                {
                    f = 1;
                    break;
                }
            }
            if (f)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}