#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
int main()
{
    optimize();
    string d1, d2;
    cin >> d1 >> d2;
    vector<string> days = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
    auto it = find(days.begin(), days.end(), d1);
    int index = distance(days.begin(), it);
    bool flag = false;
    int i, j;
    for (i = index, j = 1; i < 7 && j <= 31; j++, i++)
    {
        if (j == 28 || j == 30 || j == 31)
        {
            i++;
            if (i == 7)
            {
                if (days[0] == d2)
                {
                    cout << "YES" << endl;
                    flag = true;
                }
            }
            else if (days[i] == d2)
            {
                cout << "YES" << endl;
                flag = true;
            }

            else
            {
                i--;
            }
        }
        if (i >= 6)
        {
            i = -1;
        }
    }
    if (!flag)
        cout << "NO" << endl;

    return 0;
}