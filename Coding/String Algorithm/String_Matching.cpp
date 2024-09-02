#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

int main()
{
    optimize();
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();

    ll ar[n + 4];
    ar[0] = 0;
    ll val = 0;
    ll prime = 7;

    for (ll i = 0; i < n; i++)
    {
        ar[i + 1] = (((ar[i] * prime) % mod) + s[i]) % mod;
    }

    for (ll i = 0; i < m; i++)
        val = (((val * prime) % mod) + t[i]) % mod; // hash value of t string
    // cout<<val<<endl;

    ll val2 = 1;
    for (ll i = 1; i <= m; i++)
        val2 = (prime * val2) % mod;

    // cout<<"hi "<<val2<<endl;

    ll cnt = 0;

    for (ll i = m; i <= n; i++)
    {
        ll ans = ar[i];
        ll ans1 = ar[i - m];
        ans1 = (ans1 * val2) % mod;
        ans = ans - ans1;
        if (ans < 0)
            ans += mod;
        if (ans == val)
            cnt++;
        // cout<<ans<<endl;
    }
    cout << cnt << endl;
    return 0;
}