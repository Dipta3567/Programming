#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
bool subset_count(int n, vector<int> &v, int sum)
{
    if (n == 0)
    {
        if (sum == 0)
            return true;
        return false;
    }
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (v[n - 1] <= sum)
    {
        bool op1 = subset_count(n - 1, v, sum - v[n - 1]);
        bool op2 = subset_count(n - 1, v, sum);
        return dp[n][sum] = op1 || op2;
    }
    else
        return dp[n][sum] = subset_count(n - 1, v, sum);
}
int main()
{
    int t, i, n, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;

        vector<int> v(n);
        for (i = 0; i < n; i++)
            cin >> v[i];
        int sum = 1000 - x;
        memset(dp, -1, sizeof(dp));
        if (subset_count(n, v, sum))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}