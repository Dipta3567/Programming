#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

ll power(ll base, ll p)
{
    ll ans = 1;
    while (p)
    {
        if (p % 2)
        {
            ans = (ans * base) % mod;
            p--;
        }
        else
        {
            base = (base * base) % mod;
            p /= 2;
        }
    }
    return ans % mod;
}

ll inverse(ll x)
{
    return power(x, mod - 2);
}

ll nCr(ll n, ll r)
{
    if (r > n)
        return 0;

    ll num = 1, den = 1;
    for (ll i = n - r + 1; i <= n; i++)
    {
        num = (num * i) % mod;
    }
    for (ll i = 1; i <= r; i++)
    {
        den = (den * i) % mod;
    }
    return (num * inverse(den)) % mod;
}

int main()
{
    ll n, r;
    cin >> n >> r;
    cout << nCr(n, r) << endl;
    return 0;
}