#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll  r, c;
ll arr[10][10];
ll dp[10][10];
ll knapsack(ll i, ll j)
{
    if (i == r && j == c)
        return arr[i][j];
    if (i > r || j > c)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll op1=knapsack(i + 1, j);
    ll op2=knapsack(i, j + 1);
    return dp[i][j] = max(op1,op2) + arr[i][j];
}
int main()
{
    ll i, j;
    cin >> r >> c;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    cout << knapsack(1, 1) << endl;
    return 0;
}