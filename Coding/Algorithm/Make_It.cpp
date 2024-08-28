#include <bits/stdc++.h>
using namespace std;
bool knapsack(int i, int n, vector<int> &dp)
{
    if (i == n)
        return true;
    if (i > n)
        return false;
    if (dp[i] != -1)
        return dp[i];
    bool op1 = knapsack(i + 3, n, dp);
    bool op2 = knapsack(i * 2, n, dp);
    return dp[i] = op1 || op2;
}
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> dp(n + 1, -1);
        if (knapsack(1, n, dp))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}