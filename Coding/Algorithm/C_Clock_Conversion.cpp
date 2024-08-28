#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
int main()
{
    optimize();
    int t;
    cin >> t;
    while (t--)
    {
        int h, m;
        char c;
        cin >> h >> c >> m;
        if (h == 0)
        {
            if (m == 0 || m < 10)
                cout << "12" << c << "0" << m << " AM\n";
            else
                cout << "12" << c << m << " AM\n";
        }
        else if (h > 0 && h < 12)
        {
            if (h < 10)
            {
                cout << "0" << h << c;
                if (m == 0 || m < 10)
                    cout << "0" << m << " AM\n";
                else
                    cout << m << " AM\n";
            }

            else
            {
                cout << h << c;
                if (m == 0 || m < 10)
                    cout << "0" << m << " AM\n";
                else
                    cout << m << " AM\n";
            }
        }
        else if (h == 12)
        {
            cout << h << c;
            if (m == 0 || m < 10)
                cout << "0" << m << " PM\n";
            else
                cout << m << " PM\n";
        }
        else if (h > 12)
        {
            h -= 12;
            if (h < 10)
            {
                cout << "0" << h << c;

                if (m == 0 || m < 10)
                    cout << "0" << m << " PM\n";
                else
                    cout << m << " PM\n";
            }
            else
            {
                cout << h << c;

                if (m == 0 || m < 10)
                    cout << "0" << m << " PM\n";
                else
                    cout << m << " PM\n";
            }
        }
    }
    return 0;
}