#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool knapsack(ll x, ll n)
{
    if (x == n)
        return true;
    if (x > n)
        return false;
    
    bool op1 = knapsack(x * 10, n);
    bool op2 = knapsack(x * 20, n);
    if (op1 || op2)
        return true;
    else
        return false;
}
int main()
{
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (knapsack(1, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}