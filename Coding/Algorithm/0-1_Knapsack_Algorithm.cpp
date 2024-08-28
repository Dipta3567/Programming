#include <bits/stdc++.h>
using namespace std;
int knapsack(int n, int weight[], int value[], int w)
{
    if (n < 0 || w == 0) // Base Case
        return 0;
    if (weight[n] <= w)
    {
        // duita option
        //  niye dekbo or na niye dekbo
        int op1 = knapsack(n - 1, weight, value, w - weight[n]) + value[n];
        int op2 = knapsack(n - 1, weight, value, w);
        return max(op1, op2);
    }
    else
    {
        // ekta option
        // na niye dekte hobe
        int op2 = knapsack(n - 1, weight, value, w);
        return op2;
    }
}
int main()
{
    // This algorithm is used for for deciding between choices
    int n, i, w;
    cin >> n;
    int weight[n], value[n];
    for (i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    cin >> w;
    cout << knapsack(n - 1, weight, value, w) << endl; // n-1 er jagai n use korle base case e n==0 and weight and value e n-1 use korte hobe

    return 0;
}

/*-----------------------------------------------------   Bottom Up Approch    ----------------------------------------------------------------------------*/

// 0-1 Knapsack Bottom Up Implementation

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, w;
    cin >> n;
    int weight[n], value[n];

    for (i = 0; i < n; i++)
        cin >> weight[i];

    for (i = 0; i < n; i++)
        cin >> value[i];

    cin >> w;

    int dp[n + 1][w + 1];

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) //  if (n == 0 || w == 0)  return 0;  // Base Case
                dp[i][j] = 0;
        }
    }

    // n=1 and w=j
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (weight[i - 1] <= j)
            {
                int op1 = dp[i - 1][j - weight[i - 1]] + value[i - 1]; // int op1 = knapsack(n - 1, weight, value, w - weight[n]) + value[n];
                int op2 = dp[i - 1][j];                                // int op2 = knapsack(n - 1, weight, value, w);
                dp[i][j] = max(op1, op2);
            }
            else
            {
                int op2 = dp[i - 1][j];
                dp[i][j] = op2;
            }
        }
    }

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    // jodi full weight use kori tahole last er dike ans ta pabo

    return 0;
}

// Unbounded Knapsack Implementation

#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int unbounder_Knapsack(int n, int s, vector<int> &val, vector<int> &weight)
{
    if (n == 0 || s == 0)
        return 0;
    if (dp[n][s] != -1)
        return dp[n][s];
    if (weight[n - 1] <= s)
    {
        int ch1 = unbounder_Knapsack(n, s - weight[n - 1], val, weight) + val[n - 1];
        int ch2 = unbounder_Knapsack(n - 1, s, val, weight);
        return dp[n][s] = max(ch1, ch2);
    }
    else
        return dp[n][s] = unbounder_Knapsack(n - 1, s, val, weight);
}
int main()
{
    int n, w, i, j;
    cin >> n >> w;
    vector<int> val(n);
    vector<int> weight(n);
    memset(dp, -1, sizeof(dp));
    for (i = 0; i < n; i++)
        cin >> val[i];
    for (i = 0; i < n; i++)
        cin >> weight[i];
    cout << unbounder_Knapsack(n, w, val, weight);
    return 0;
}

// Unbounded Knapsack Implementation input:
/*

4 6
5 3 2 4
4 1 3 2

*/

// Unbounded Knapsack Bottom Up approch

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, s, i, j;
    cin >> n >> s;
    vector<int> val(n);
    vector<int> weight(n);
    int dp[n + 1][s + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= s; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++)
        cin >> val[i];
    for (i = 0; i < n; i++)
        cin >> weight[i];

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= s; j++)
        {
            if (weight[i - 1] <= j)
            {
                dp[i][j] = max(dp[i][j - weight[i - 1]] + val[i - 1], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}

// Count of subset sum or coin change 1 : akane koybhabe subset niye target sum banano jai ota count kora hoi

/*

3
1 2 3
5
output : 5

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, s, j;
    cin >> n;
    vector<int> w(n);
    for (i = 0; i < n; i++)
        cin >> w[i];
    cin >> s;
    int dp[n + 1][s + 1];
    dp[0][0] = 1;
    for (i = 1; i <= s; i++)
        dp[0][i] = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= s; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - w[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}

// Count of subset sum or coin change 2 : akane minimum koto ta coin niye target sum hobe ota count korbe
/*

3
1 2 3
5
output : 2

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, s, j;
    cin >> n;
    vector<int> w(n);
    for (i = 0; i < n; i++)
        cin >> w[i];
    cin >> s;
    int dp[n + 1][s + 1];
    dp[0][0] = 0;
    for (i = 1; i <= s; i++)
        dp[0][i] = INT_MAX - 1;

    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= s; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = min(dp[i][j - w[i - 1]] + 1, dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[n][s] == INT_MAX - 1)
        cout << "NOT POSSIBLE\n";
    else
        cout << dp[n][s] << endl;

    return 0;
}
