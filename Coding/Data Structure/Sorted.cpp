#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
    optimize();
    ll t;
    cin >> t;
    while (t--)
    {
        int n,i;
        list<int>l;
        cin >> n;
        for (i=0;i<n;i++)
        {
            int x;
            cin >> x;
            l.push_back(x);
        }
        l.sort();
        l.unique();
        for (auto u : l)
        cout << u << " ";
        cout << endl;

    }
    return 0;
}