#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
    optimize();
    ll n, t, i, x;
    cin >> n >> t;
    vector<ll> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    while (t--)
    {
        cin >> x;
        ll l = 0, r = n - 1;
        ll flag = 0, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (v[mid] != x)
            {
                if (v[mid] < x)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid-1;
                }
            }
            else
                {
                    flag = 1;
                    break;
                }
        }
        if (flag == 1)
            cout << "found\n";
        else
            cout << "not found\n";
    }
    return 0;
}