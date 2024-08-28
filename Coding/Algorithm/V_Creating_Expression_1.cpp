#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool subset_count(ll n, vector<ll> &v, ll des)
{
    if (n == 1)
    {
        if (des == 0)
            return true;
        return false;
    }

    if (v[n - 1] <= des)
    {
        int op1 = subset_count(n - 1, v, des - v[n - 1]);
        int op2 = subset_count(n - 1, v, des);
        return op1 || op2;
    }
    else
    {
        return subset_count(n - 1, v, des);
    }
}
int main()
{
    ll n, i, des, diff;
    cin >> n >> diff;
    vector<ll> v(n);
    ll s = 0;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        s += v[i];
    }
    des = (s + diff);
    if (des % 2 == 0)
    {
        des /= 2;

        if (subset_count(n, v, des - v[0]))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
        cout << "NO\n";
    return 0;
}