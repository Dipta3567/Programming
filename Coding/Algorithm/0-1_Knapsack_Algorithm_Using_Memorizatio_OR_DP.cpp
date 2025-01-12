// Top down approch
#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000;
const int maxW = 1000;
int dp[maxN][maxW]; // dp use korai ata O(N X W) hoyse ja ager O(2 ^ N) theke onek better
int knapsack(int n, int weight[], int value[], int w)
{
    if (n == 0 || w == 0) // Base Case
    {
        return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }

    if (weight[n - 1] <= w)
    {
        // duita option
        //  niye dekbo or na niye dekbo
        int op1 = knapsack(n - 1, weight, value, w - weight[n - 1]) + value[n - 1];
        int op2 = knapsack(n - 1, weight, value, w);
        return dp[n][w] = max(op1, op2);
    }
    else
    {
        // ekta option
        // na niye dekte hobe
        int op2 = knapsack(n - 1, weight, value, w);
        return dp[n][w] = op2;
    }
}
int main()
{
    // This algorithm is used for for deciding between choices
    int n, i, w, j;
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
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= w; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n, weight, value, w) << endl; // n-1 er jagai n use korle base case e n==0 and weight and value e n-1 use korte hobe

    return 0;
}


// Bottom up ( Best for CP)

#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - wt[i-1]] + val[i-1]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int n = 3, W = 50;
    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};

    cout << "Max Benefit: " << knapsack(W, wt, val, n) << endl;
    return 0;
}
