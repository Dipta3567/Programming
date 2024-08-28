#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll N=1e6+5;
ll dp[N];
// this recursion is top down approch ( not the memorixation only the recursion)
ll fun(ll n)
{
    if (n==1 || n==2)
    return n-1;
    if (dp[n]!=-1)
    {
        return dp[n];
    }
    ll ans=fun(n-1)+fun(n-2);
    dp[n]=ans;
    return ans;
}

int main()
{
    optimize();
    ll n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << fun(n) << endl;
    return 0;
}