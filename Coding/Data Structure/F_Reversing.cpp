#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    optimize();
    int i,n;
    cin >> n;
    vector <int>v(n);
    for (i=0;i<n;i++)
    cin >> v[i];
    reverse(v.begin(),v.end());
    for (auto u : v)
    cout << u << " ";
    return 0;
}