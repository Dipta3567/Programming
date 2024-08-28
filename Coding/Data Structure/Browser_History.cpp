#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    list<string> sl;
    list<string>::iterator it, tmp;
    string s, q;
    while (true)
    {

        cin >> s;
        if (s == "end")
            break;
        sl.push_back(s);
    }
    int x;
    cin >> x;
    tmp = it;
    while (x--)
    {
        cin >> q;
        if (q == "visit")
        {
            cin >> s;
            it = find(sl.begin(), sl.end(), s);
            if (it == sl.end())
            {
                it = tmp;
                cout << "Not Available\n";
            }
            else
            {
                cout << *it << endl;
                tmp = it;
            }
        }
        else if (q == "next")
        {
            it++;
            if (it == sl.end())
            {
                it--;
                cout << "Not Available\n";
            }
            else
            {
                cout << *it << endl;
                tmp = it;
            }
        }

        else if (q == "prev")
        {
            it--;
            if (it == sl.end())
            {
                it++;
                cout << "Not Available\n";
            }
            else
            {
                cout << *it << endl;
                tmp = it;
            }
        }
    }

    return 0;
}