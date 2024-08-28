#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    list<ll> mylist;
    int t, q, v;
    cin >> t;
    while (t--)
    {
        cin >> q >> v;
        if (q == 0)
        {
            mylist.push_front(v);
            cout << "L -> ";
            for (auto u : mylist)
                cout << u << " ";
            cout << endl;
            cout << "R -> ";
            mylist.reverse();
            for (auto u : mylist)
                cout << u << " ";
            cout << endl;
            mylist.reverse();
        }
        else if (q == 1)
        {
            mylist.push_back(v);
            cout << "L -> ";
            for (auto u : mylist)
                cout << u << " ";
            cout << endl;
            cout << "R -> ";
            mylist.reverse();
            for (auto u : mylist)
                cout << u << " ";
            cout << endl;
            mylist.reverse();
        }
        else if (q == 2)
        {
            if (v < mylist.size())
                mylist.erase(next(mylist.begin(), v));
            cout << "L -> ";
            for (auto u : mylist)
                cout << u << " ";
            cout << endl;
            cout << "R -> ";
            mylist.reverse();
            for (auto u : mylist)
                cout << u << " ";
            cout << endl;
            mylist.reverse();
        }
    }
    return 0;
}