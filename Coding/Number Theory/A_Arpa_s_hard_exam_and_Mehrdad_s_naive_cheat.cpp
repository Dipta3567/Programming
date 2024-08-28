#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int

ll binary(ll base,ll power,ll mod)
{
    ll res=1;
    while(power > 0)
    {
        if (power %2!=0)
        {
            res=(res*base)%mod;
            power=power-1;
        }
        else
        {
            base=(base*base)%mod;
            power=power/2;
        }
    }
    return res;
}
int main()
{
    optimize();
    ll n;
    cin >> n;
    cout << binary(1378,n,10) << endl;
    return 0;
}