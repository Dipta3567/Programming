/*

Its only for finding prime numbers in a range.

L = 21 and R = 30

Range = 30 - 21 + 1 = 10
arr[10] = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30}
sqrt(30) = 5.47 = 5 = 2, 3 ,5 is the prime numbers

g= (l/prime) * prime = (21/2) * 2 = 20 its not in range so  we have to + prime = 22 . now i have to mark all the divisible numbers of 2 in the range.

g= (21/3) * 3 = 21 its in the range so we have to mark all the divisible numbers of 3 in the range.

g= (21/5) * 5 = 20 its not in the range so we have to + prime = 25. now i have to mark all the divisible numbers of 5 in the range.

so the main formula is : g = (l/prime) * prime
                          if(g < l) g += prime
                          for(int i = g; i <= r; i += prime) arr[i - l] = 1;



*/

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int

vector<ll> v;
void sieve(int n)
{
    ll prime[100001];
    memset(prime,0,sizeof(prime));
    for (ll i = 2; i * i <= n; i++)
    {
        if(prime[i] == 0)
        {
            for (ll j = i * i; j <= n; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    for (ll i = 2; i <= n; i++)
    {
        if(prime[i] == 0)
            v.push_back(i);
    }
}

void init(ll l, ll r)
{
    if (l==1)
        l++;
    ll range = r - l + 1;
    ll arr[range+1];
    for (ll i = 0; i <= range; i++)
    {
        arr[i] = 0;
    }
    
    for (ll p : v)
    {
        if(p * p <= r)
        {
            ll g = (l/p) * p;
            if(g < l)
                g += p;
            for (ll i = g; i <= r; i += p)
            {
                arr[i - l] = 1;
            }
        }
    }


    for (ll i = 0; i < range; i++)
    {
        if(arr[i] == 0)
            cout << i + l << endl;
    }
}

int main()
{
    //optimize();
    sieve(100000);
    ll t,l,r;
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        init(l,r);
        cout << endl;
    }
    
    return 0;
}