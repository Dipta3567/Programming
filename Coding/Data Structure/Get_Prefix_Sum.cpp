#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
    optimize();
    ll n,i;
    cin >> n;
    vector<ll> v(n),sum;
    for (i=0;i<n;i++)
    {
        cin >> v[i];
        if (i==0)
        sum.push_back(v[i]);
        else
        sum.push_back(sum[i-1]+v[i]);
    }
    reverse(sum.begin(),sum.end());
    for (auto u : sum)
    cout << u << " ";
    return 0;
}