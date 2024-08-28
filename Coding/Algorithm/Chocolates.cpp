#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, i, n, j;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int s = 0;
        vector<int> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
            s += v[i];
        }
        if (s % 2 == 0)
        {
            int sum = s / 2;
            bool dp[n + 1][sum + 1];
            dp[0][0] = true;
            for (i = 1; i <= sum; i++)
                dp[0][i] = false;
            for (i = 1; i <= n; i++)
            {
                for (j = 0; j <= sum; j++)
                {
                    if (v[i - 1] <= j)
                    {
                        dp[i][j] = dp[i - 1][j - v[i - 1]] || dp[i - 1][j];
                    }
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
            if (dp[n][sum])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}