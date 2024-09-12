/*
Given a number N, find its prime factorization.
example:
    N=100
    factorization: (2^2) * (5^2)

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// Brute Force Approach

ll N = (7 ^ 3) * (13 ^ 1) * (23 ^ 12);

void primefact(ll N) // Time : O(N)
{
    for (ll i = 2; i <= N; i++)
    {
        if (N % i == 0)
        {
            ll cnt = 0;
            while (N % i == 0)
            {
                cnt++;
                N = N / i;
            }
            cout << i << "^" << cnt << endl;
        }
    }
}

// Optimized Approach

void primeFact_opt(int N) // Time : O(sqrt(N))
{
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            int cnt = 0;
            while (N % i == 0)
            {
                cnt++;
                N = N / i;
            }
            cout << i << "^" << cnt << endl;
        }
    }
    if (N > 1)
        cout << N << "^" << 1 << endl;
}



// new approach , its used for the problem divisors and reciprocals, its in the Divisors_and_Reciprocals.cpp file

ll power(ll base,ll n)
{
    ll result=1;
    while(n)
    {
        if(n%2==1)
        {
            result*=base;
            n--;
        }
        else
        {
            base*=base;
            n/=2;
        }
    }
    return result;
}

ll primefact(int n)
{
    ll res=1;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i == 0)
            {
                cnt++;
                n=n/i;
                //cout<<"kd"<<nl;
            }
            //cout<<i<<"^"<<cnt<<",";
            res*=((power(i,cnt+1)-1)/(i-1));
        }
    }
    if(n>1)
    {
        res*=((power(n,2)-1)/(n-1));
        //cout<<n<<"^"<<1<<nl;
    }

    return res;
}



int main()
{
    cout << N << endl;
    primefact(N);
    cout << endl
         << endl;
    primeFact_opt(N);
    return 0;
}
