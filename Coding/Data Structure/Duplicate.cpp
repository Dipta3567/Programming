#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
    optimize();
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll i, size;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    size=unique(v.begin(),v.end())-v.begin();
    if (size==n)
        cout << "NO\n";
    else
        cout << "YES\n";

    return 0;
}