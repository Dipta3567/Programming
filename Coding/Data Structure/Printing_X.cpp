#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    optimize();
    int n, i, j, s, e;
    cin >> n;
    s = 0, e = n - 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == s && s < e)
            {
                cout << "\\";
            }
            else if (j == e && e > s)
            {
                cout << "/";
            }
            else if (e == s && j == e)
            {
                cout << "X";
            }
            else if (j == s && s > e)
            {
                cout << "\\";
            }
            else if (j == e && e < s)
            {
                cout << "/";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        s++;
        e--;
    }
    return 0;
}
