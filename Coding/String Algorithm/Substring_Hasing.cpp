/*

s=abcde

we have to find hash of bcd

arr[1]= a
arr[2]= (a*p+b)
arr[3]= (a*p^2+b*p+c)
arr[4]= (a*p^3+b*p^2+c*p+d)
arr[5]= (a*p^4+b*p^3+c*p^2+d*p+e)

akon bcd er hash ber korte hobe tahole
d=arr[4]= (a*p^3+b*p^2+c*p+d)
akane a*p^3 er value ta minus kore dile bcd er hash pai jabo

arr[1]= a kintu akane ase p^3 so otar jonno arr[1]*p^3 korte hobe p er power ta sustring er size diye ber kora jai, substring bcd er hash ber korte hobe ty size 3.

arr[4]-arr[1]*p^3= (a*p^3+b*p^2+c*p+d)-(a*p^3)
                  = b*p^2+c*p+d

so, bcd er hash ber korte hobe arr[4]-arr[1]*p^3

******jodi de er korte cai tahole size 4 to 5

arr[5]= (a*p^4+b*p^3+c*p^2+d*p+e)
arr[3]= (a*p^2+b*p+c)
arr[5]-arr[3]= (a*p^4+b*p^3+c*p^2+d*p+e)-(a*p^2+b*p+c) kintu size same hoi nai
de er size 2 so p^2  arr[3] er value ta multiply korte hobe
so , arr[5]-arr[3]*p^2= (a*p^4+b*p^3+c*p^2+d*p+e)-(a*p^2+b*p+c)*p^2
                    = (a*p^4+b*p^3+c*p^2+d*p+e)-(a*p^4+b*p^3+c*p^2)
                    = d*p+e



*/

#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

ll power(ll prime, ll sz)
{
    ll ans = 1;
    for (ll i = 1; i <= sz; i++)
    {
        ans = (ans * prime) % mod;
    }
    return ans;
}

int main()
{
    optimize();
    string s;
    cin >> s;
    int n = s.size();
    ll arr[n + 10];
    ll prime = 7;
    arr[0] = 0;
    ll i, j;
    for (i = 0; i < n; i++)
    {
        arr[i + 1] = (((arr[i] * prime) % mod) + s[i]) % mod;
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        ll sz = r - l + 1;
        ll ans1 = arr[r];
        ll ans2 = arr[l - 1];
        ll pw = power(prime, sz);
        ans2 = (ans2 * pw) % mod;
        ll ans = ans1 - ans2;
        cout << ans << endl;
    }
    return 0;
}

// https://cses.fi/problemset/task/1753/


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