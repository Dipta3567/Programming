/*------------------------------------------------------------Top Down------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
bool subset_sum(int n, vector<int> &v, int sum)
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
        bool op1 = subset_sum(n - 1, v, sum - v[n - 1]);
        bool op2 = subset_sum(n - 1, v, sum);
        return dp[n][sum] = op1 || op2;
    }
    else
    {
        return dp[n][sum] = subset_sum(n - 1, v, sum);
    }
}
int main()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    int sum;
    cin >> sum;
    memset(dp, -1, sizeof(dp));
    if (subset_sum(n, v, sum))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

/*-------------------------------------------------------------Bottom Up-----------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    cin >> n;
    vector<int> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    int s;
    cin >> s;
    bool dp[n + 1][s + 1];

    dp[0][0] = true;
    for (i = 1; i <= s; i++)
        dp[0][i] = false;

    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= s; j++)
        {
            if (v[i - 1] <= j)
            {
                bool op1 = dp[i - 1][j - v[i - 1]]; // nisi
                bool op2 = dp[i - 1][j];            // ni nai

                dp[i][j] = op1 || op2;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[n][s])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

/*-----------------------------------------------------------Count of Subset Sum Top Down-----------------------------------------------------------------------------*/

// ata kotobhabe banano jai ota count kore dibe, koyta use kore count korse ota na
/*
6
2 3 5 6 8 10
10
*/

#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int subset_sum_Count(int n, vector<int> &v, int sum)
{
    if (n == 0)
    {
        if (sum == 0)
            return 1;
        return 0;
    }
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (v[n - 1] <= sum)
    {
        int op1 = subset_sum_Count(n - 1, v, sum - v[n - 1]);
        int op2 = subset_sum_Count(n - 1, v, sum);
        return dp[n][sum] = op1 + op2;
    }
    else
    {
        return dp[n][sum] = subset_sum_Count(n - 1, v, sum);
    }
}
int main()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    int sum;
    cin >> sum;
    memset(dp, -1, sizeof(dp));
    cout << subset_sum_Count(n, v, sum) << endl;

    return 0;
}

/*------------------------------------ Equal Sum Partition using Subset Sum -----------------------------------------------------------------------------------------------------*/
// input:
// 4
// 1 4 9 4 ekane 2 ta subset jog kore same sum hoi naki check kora hobe

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    cin >> n;
    vector<int> v(n);
    int s = 0;
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
    return 0;
}

/*------------------------------------------------------- Minimum Subset Sum Difference -------------------------------------------------------------------------------------*/

// ata 2 ta subset sum  er minimum difference ber kore
// 4
// 1 5 4 11 akane ans hobe 1 karon min difference is 1
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    cin >> n;
    vector<int> v(n);
    int s = 0;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        s += v[i];
    }
    bool dp[n + 1][s + 1];
    dp[0][0] = true;
    for (i = 1; i <= s; i++)
        dp[0][i] = false;

    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= s; j++)
        {
            if (v[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - v[i - 1]] || dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    vector<int> sum;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= s; j++)
        {
            if (dp[i][j] == 1)
                sum.push_back(j);
        }
    }
    int ans = INT_MAX;
    for (auto val : sum)
    {
        int s1 = val;
        int s2 = s - s1;
        ans = min(ans, abs(s1 - s2));
    }
    cout << ans << endl;
    return 0;
}

/*--------------------------------------------- Count Subset Sum with Given Difference  or Target Sum -----------------------------------------------------------------------------------------*/

/* deya ase arr: 1 1 2 3  and diff = 1, akon  amake count korte hobe koyta subset er dif 1 , akane ans hocce 3  */

#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int subset_sum_count(int n, vector<int> &v, int des)
{
    if (n == 0)
    {
        if (des == 0)
            return 1;
        return 0;
    }
    if (dp[n][des] != -1)
        return dp[n][des];
    if (v[n - 1] <= des)
    {
        int op1 = subset_sum_count(n - 1, v, des - v[n - 1]);
        int op2 = subset_sum_count(n - 1, v, des);
        return dp[n][des] = op1 + op2;
    }
    else
    {
        return dp[n][des] = subset_sum_count(n - 1, v, des);
    }
}
int main()
{
    int n, i, j;
    cin >> n;
    vector<int> v(n);
    int s = 0;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        s += v[i];
    }
    int diff;
    cin >> diff;
    int des = (s + diff) / 2;

    memset(dp, -1, sizeof(dp));
    cout << subset_sum_count(n, v, des) << endl;
    return 0;
}



// Target Sum er arek ta better way : https://leetcode.com/problems/target-sum/

// online solution

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int offset = 1000;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2001, 0));
        dp[0][offset] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int sum = -1000; sum <= 1000; sum++) {
                if (dp[i][sum + offset] > 0) {
                    dp[i + 1][sum + nums[i] + offset] += dp[i][sum + offset];
                    dp[i + 1][sum - nums[i] + offset] += dp[i][sum + offset];
                }
            }
        }
        return (target > 1000) ? 0 : dp[nums.size()][target + offset];
    }
};

// My solution

class Solution {
public:
int dp[1010][2020];
int subset_count(int n,vector<int>&v,int des)
{
    if (n==0)
    {
        if (des==0)
        return 1;
        return 0;
    }
    if (dp[n][des+1000]!=-1)
    return dp[n][des+1000];
    if (v[n-1]<=des)
    {
        int op1=subset_count(n-1,v,des-v[n-1]);
        int op2=subset_count(n-1,v,des);
        return dp[n][des+1000]=op1+op2;
    }
    else
    return dp[n][des+1000]=subset_count(n-1,v,des);
}
    int findTargetSumWays(vector<int>& v, int diff) {
        if (v.size()==0 || (diff>0 && v.size()==1 && diff-v[0]!=0))
        return 0;
        if (diff<0 && v.size()==1)
        {
            diff*=-1;
            if (diff==v[0])
            return 1;
            else
            return 0;
        }
        if (v.size()==1 && diff-v[0]==0)
        return 1;
        int s=0;
        for (auto u : v)
        s+=u;
        int des=(s+diff);
        if (des%2==0)
        {
            des/=2;
            memset(dp,-1,sizeof(dp));
            return subset_count(v.size(),v,des);
        }
        else
        return 0;
    }
};





// Count Subset Sum with Given Difference  or Target Sum problem
/*

problem link : https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/V

problem description : 
--------------------

Given two numbers N
 ,X
 and an array A
 of N
 numbers. Determine if there is a way to put '+' or '-' signs between every two numbers in the array A
 in order to make an expression that is equal to X
.

Note: Solve this problem using recursion.

Input
First line contains two numbers N
 and X
 (1≤N≤20,−109≤X≤109)
.

Second line contains N
 distinct numbers A1,A2,....AN
 (1≤Ai≤105)
.

Output
Print "YES" if you can put '+' or '-' signs between every two number to create an expression that is equal to X
 otherwise, print "NO".

Examples
inputCopy
5 5
1 2 3 4 5
outputCopy
YES
inputCopy
5 2
1 2 3 4 5
outputCopy
NO
Note
In the first example: 1 - 2 - 3 + 4 + 5 = 5

*/

// code : 

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool subset_count(ll n, vector<ll> &v, ll des)
{
    if (n == 1)
    {
        if (des == 0)
            return true;
        return false;
    }

    if (v[n - 1] <= des)
    {
        int op1 = subset_count(n - 1, v, des - v[n - 1]);
        int op2 = subset_count(n - 1, v, des);
        return op1 || op2;
    }
    else
    {
        return subset_count(n - 1, v, des);
    }
}
int main()
{
    ll n, i, des, diff;
    cin >> n >> diff;
    vector<ll> v(n);
    ll s = 0;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        s += v[i];
    }
    des = (s + diff);
    if (des % 2 == 0)
    {
        des /= 2;

        if (subset_count(n, v, des - v[0]))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
        cout << "NO\n";
    return 0;
}