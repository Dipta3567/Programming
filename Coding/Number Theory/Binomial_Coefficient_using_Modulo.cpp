/*

        n                      n!
          c         =    ----------------
            r               r! * (n-r)!

let n! = n1,  r! = r1,  (n-r)! = k

                               n1
                   =    ----------------
                            r1 * k


                   =    (n1 * r1^-1 * k^-1) % mod // mod = 1e9+7



                   =    ( n1 % mod ) * ( (r1 ^ mod-2) % mod ) * ( (k ^ mod-2) % mod ) % mod




*/

#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

ll fact(ll n)
{
    ll ans = 1;
    for (ll i = 2; i <= n; i++)
    {
        ans = (ans * i) % mod;
    }
    return ans % mod;
}

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

ll nCr(ll n1, ll r1, ll k)
{
    ll ans, ans1, ans2;
    ans1 = power(r1, mod - 2)%mod;
    ans2 = power(k, mod - 2)%mod;
    ans = (n1 * ans1) % mod;
    ans = (ans * ans2) % mod;
    return ans % mod;
}

int main()
{
    optimize();
    ll n, r, n1, r1, k;
    cin >> n >> r;
    n1 = fact(n);

    r1 = fact(r);
    k = fact(n - r);

    ll ans = nCr(n1, r1, k);

    cout << ans << endl;

    return 0;
}

// Upper code has some issues :
/*

Issues:
Wrong Calculation in nCr function:

The way nCr is calculated is incorrect. You are passing n1, r1, and k to nCr, which are factorials of n, r, and n - r, respectively, but these factorial values should not be passed directly as parameters.
You need to calculate the modular inverse of the denominator (r! * (n-r)!) % mod, not the modular inverse of r and k separately.
Inverses of factorials:

You should calculate fact(r) and fact(n-r) and then multiply their modular inverses together. The modular inverse calculation should be applied to the whole denominator (r! * (n-r)!).
Input Validation:

You should add a check for the case when r > n or r < 0, as binomial coefficients are not defined in those cases.


*/

// Corrected Code:

#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

// Function to calculate factorial modulo 'mod'
ll fact(ll n)
{
    ll ans = 1;
    for (ll i = 2; i <= n; i++)
    {
        ans = (ans * i) % mod;
    }
    return ans % mod;
}

// Function to calculate (base^p) % mod using binary exponentiation
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

// Function to calculate nCr % mod
ll nCr(ll n, ll r)
{
    if (r > n || r < 0)
        return 0; // nCr is 0 when r > n or r < 0

    ll nFact = fact(n);       // n!
    ll rFact = fact(r);       // r!
    ll n_rFact = fact(n - r); // (n - r)!

    // Using Fermat's Little Theorem to calculate the modular inverse of r! * (n-r)!
    ll denominator = (rFact * n_rFact) % mod;
    ll denominatorInverse = power(denominator, mod - 2); // Inverse of denominator

    // Final result: nCr = n! / (r! * (n - r)!)
    return (nFact * denominatorInverse) % mod;
}

int main()
{
    optimize();
    ll n, r;
    cin >> n >> r;

    // Calculating nCr % mod
    ll ans = nCr(n, r);
    cout << ans << endl;

    return 0;
}

// Faster code Avoids precomputing full factorials and instead computes the numerator directly

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
