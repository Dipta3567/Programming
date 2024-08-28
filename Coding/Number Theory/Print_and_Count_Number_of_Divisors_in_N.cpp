/*

The divisor of 12 -->  1,2,3,4,6,12 

*/

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
int main()
{
    optimize();
    ll i, n;
    cin >> n;
    set<ll>s;
    for (i=1;i<=sqrt(n);i++)
    {
        if (n%i==0)
        {
            ll x=i;
            ll y=n/i;
            s.insert(x);
            s.insert(y);
        }
    }

    cout << s.size() << endl;
    for (auto u : s)
    cout << u << " ";
    

    return 0;
}