#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
    //optimize();
    list<ll>l;
    int x;
    while (true)
    {
        cin >> x;
        if (x==-1)
        break;
        l.push_back(x);
    }
    l.sort();
    l.unique();
    for (auto u : l)
    cout << u << " ";
    return 0;
}