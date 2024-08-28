#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    queue<string> q;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 0)
        {
            cin.ignore();
                string s;
            cin >> s;
            q.push(s);
        }
        else
        {
            if (!q.empty())
            {
                cout << q.front() << endl;
                q.pop();
            }
            else
            cout << "Invalid" << endl;
        }
    }

    return 0;
}