#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int knapsack(int n, int weight[], int value[], int w)
{
    if (n < 0 || w == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (weight[n] <= w)
    {
        int op1 = knapsack(n - 1, weight, value, w - weight[n]) + value[n];
        int op2 = knapsack(n - 1, weight, value, w);
        return dp[n][w] = max(op1, op2);
    }
    else
        return dp[n][w] = knapsack(n - 1, weight, value, w);
}
int main()
{
    int t, i, n, w;
    cin >> t;
    while (t--)
    {
        cin >> n >> w;
        int weight[n], value[n];
        for (i = 0; i < n; i++)
            cin >> weight[i];
        for (i = 0; i < n; i++)
            cin >> value[i];
        memset(dp, -1, sizeof(dp));
        cout << knapsack(n - 1, weight, value, w) << endl;
    }
    return 0;
}