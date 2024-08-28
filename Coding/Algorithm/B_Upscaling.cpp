#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    optimize();
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 0; i < 2 * n; ++i)
        {
            for (int j = 0; j < 2 * n; ++j)
            {
                if ((i / 2 + j / 2) % 2 == 0)
                    cout << '#';
                else
                    cout << '.';
            }
            cout << '\n';
        }
    }

    return 0;
}
