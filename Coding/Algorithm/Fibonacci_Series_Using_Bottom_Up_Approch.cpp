#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    optimize();
    ll n;
    cin >> n;
    ll arr[n];
    arr[0]=0;
    arr[1]=1;
    for (int i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout << arr[n] << endl;
    return 0;
}