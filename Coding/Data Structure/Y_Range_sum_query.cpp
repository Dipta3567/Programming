#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
int main()
{
    optimize();
    ll n,t;
    cin >> n >> t;
    vector <ll> v(n),sum;
    ll i;
    for (i=0;i<n;i++)
    {
        cin >> v[i];
        if (i==0)
        sum.push_back(v[i]);
        else
        sum.push_back(sum[i-1]+v[i]);
    }
while (t--)
    {
        ll s,e;
        cin >> s >> e;
        s--;
        e--;
        if (s==0)
        cout << sum[e]<< endl;
        else
        cout << sum[e]-sum[s-1] << endl;
    }
    return 0;
}