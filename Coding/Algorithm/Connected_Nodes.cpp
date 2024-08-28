#include <bits/stdc++.h>
using namespace std;
vector<int> v[1010];

int main()
{
    int n, e, a, b, t, i;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> t;
    while (t--)
    {

        vector<int> cnt;
        cin >> a;
        for (auto u : v[a])
            cnt.push_back(u);
        if (cnt.empty())
            cout << "-1" << endl;
        else
        {
            sort(cnt.rbegin(), cnt.rend());
            for (auto u : cnt)
                cout << u << " ";
            cout << endl;
        }
    }
    return 0;
}