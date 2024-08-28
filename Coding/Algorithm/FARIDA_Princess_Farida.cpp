#include <bits/stdc++.h>
using namespace std;
int count(vector<int> &arr, vector<int> &dp, int i, int n)
{
    if (n==0 || i >= n) // n==0 means there are no monster
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int op1 = count(arr, dp, i + 1, n) + 0;
    int op2 = count(arr, dp, i + 2, n) + arr[i];
    return dp[i] = max(op1, op2);
}
int main()
{
    int t, k;
    cin >> t;
    for (k = 1; k <= t; k++)
    {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> dp(n, -1);
        cout << "Case " << k << ": " << count(arr, dp, 0, n) << endl;
    }
    return 0;
}