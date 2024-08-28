#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, i;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s, w, n;
        getline(cin, s);
        map<string, int> mp;
        stringstream ss(s);
        i = 0;
        while (ss >> w)
        {
            mp[w]++;
            if (mp[w] > i)
            {
                i = mp[w];
                n = w;
            }
        }
        cout << n << " " << i << endl;
    }

    return 0;
}