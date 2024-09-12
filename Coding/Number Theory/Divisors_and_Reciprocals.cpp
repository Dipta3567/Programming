
// https://www.codechef.com/problems/DIVREC

/*

we have given x , a,b

we have to guess a number n such that the sum of all divisor of n is equal to x and the sum of all reciprocal of divisor of n is equal to a/b.

sum of reciprocal of divisor of n means : n er shob divisor er sum ke n diye divide korle a/b er equal hobe.


we can solve it by like this

sum/n = a/b

here x= sum of divisor of n
x/n = a/b

n = x*b/a

akane akta gondogol hobe, shob gula te akane ebhave ans milbe na ,to amake n er value prime fact divisor sum ber kore x er value hole ans milbe.

*/
// this code giving me tle so we have to solve it by another way
#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

ll power(ll base, ll n)
{
    ll result = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            result *= base;
            n--;
        }
        else
        {
            base *= base;
            n /= 2;
        }
    }
    return result;
}

ll primefact(ll n)
{
    ll res = 1;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            res *= ((power(i, cnt + 1) - 1) / (i - 1)); // formula for sum of divisor of n
        }
    }
    if (n > 1)
    {
        res *= ((power(n, 2) - 1) / (n - 1));
    }
    return res; // return sum of divisor of n
}

int main()
{
    optimize();
    ll t, a, b, x;
    cin >> t;
    while (t--)
    {
        cin >> x >> a >> b;
        ll n = (x * b);
        if (n % a == 0 && primefact(n / a) == x)
        {
            cout << n / a << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}

// Another way to solve this problem by sieve of eratosthenes but this code giving me runtime error

#include <bits/stdc++.h>

using namespace std;

#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

const int MAXN = 1e7+7;
bool is_prime[MAXN];
vector<int> primes;

void precompute_primes()
{
    fill(is_prime, is_prime + MAXN, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAXN; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < MAXN; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < MAXN; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}

ll power(ll base, ll n)
{
    ll result = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            result *= base;
            n--;
        }
        else
        {
            base *= base;
            n /= 2;
        }
    }
    return result;
}

ll primefact(ll n)
{
    ll res = 1;
    for (int i = 0; primes[i] * primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
        {
            ll cnt = 0;
            while (n % primes[i] == 0)
            {
                cnt++;
                n /= primes[i];
            }
            res *= ((power(primes[i], cnt + 1) - 1) / (primes[i] - 1));
        }
    }
    if (n > 1)
    {
        res *= ((power(n, 2) - 1) / (n - 1));
    }
    return res;
}

int main()
{
    optimize();
    precompute_primes();
    ll t, a, b, x;
    cin >> t;
    while (t--)
    {
        cin >> x >> a >> b;
        ll n = (ll)(x * b); // Cast to long long int
        if (n % a == 0 && primefact(n / a) == x)
        {
            cout << n / a << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}