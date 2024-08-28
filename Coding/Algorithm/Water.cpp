#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t, n, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> v(n);
        for (i = 0; i < n; i++)
            cin >> v[i];
        vector<ll> cpy = v;
        sort(cpy.rbegin(), cpy.rend());
        ll x, y;
        for (i = 0; i < n; i++)
        {
            if (v[i] == cpy[0])
            {
                x = i;
            }
            if (v[i] == cpy[1])
                y = i;
        }
        if (x > y)
            cout << y << " " << x << endl;
        else
            cout << x << " " << y << endl;
    }
    return 0;
}