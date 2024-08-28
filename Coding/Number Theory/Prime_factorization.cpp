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

int main()
{
    cout << N << endl;
    primefact(N);
    cout << endl
         << endl;
    primeFact_opt(N);
    return 0;
}
