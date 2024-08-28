/*
Theory:

Subsequence vs Substring:

hello ->  eo ->  subsequence (Continious hote hobe mandatory na, majer char bad deya jabe)
                 Not Substring

           el -> substring ( Continious hote hobe mandatory, majer char bad deya jabe na)

*/

// Longest Common Subsequence (LCS) Top Down Implementation

/*

input :
abcdfgr
acfdgr
 kane f nile d neya jabe na and d nile f neya jabe na karon 2 ta pasha pashi ase
*/
#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int lcs(string a, int n, string b, int m)
{
      if (n == 0 || m == 0)
            return 0;
      if (dp[n][m] != -1)
            return dp[n][m];
      if (a[n - 1] == b[m - 1])
      {
            int ans = lcs(a, n - 1, b, m - 1);
            return dp[n][m] = ans + 1;
      }
      else
      {
            int ans1 = lcs(a, n - 1, b, m);
            int ans2 = lcs(a, n, b, m - 1);
            return dp[n][m] = max(ans1, ans2);
      }
}

int main()
{
      string a, b;
      cin >> a >> b;
      memset(dp, -1, sizeof(dp));
      cout << lcs(a, a.size(), b, b.size()) << endl;
      return 0;
}

// LCS Bottom Up Implementation

#include <bits/stdc++.h>
using namespace std;
int main()
{
      string a, b;
      cin >> a >> b;
      int n = a.size(), m = b.size(), i, j;
      int dp[n + 1][m + 1];
      for (i = 0; i <= n; i++)
      {
            for (j = 0; j <= m; j++)
            {
                  if (i == 0 || j == 0)
                        dp[i][j] = 0;
            }
      }
      for (i = 1; i <= n; i++)
      {
            for (j = 1; j <= m; j++)
            {
                  if (a[i - 1] == b[j - 1])
                  {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                  }
                  else
                  {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                  }
            }
      }
      cout << dp[n][m] << endl;

      // Print the Subsequence

      i = n;
      j = m;
      string ans;
      while (i != 0 && j != 0)
      {
            if (a[i - 1] == b[j - 1])
            {
                  ans += a[i - 1];
                  i--;
                  j--;
            }
            else
            {
                  if (dp[i][j - 1] > dp[i - 1][j])
                  {
                        j--;
                  }
                  else
                  {
                        i--;
                  }
            }
      }
      reverse(ans.begin(), ans.end());
      cout << ans << endl;
      return 0;
}

// Longest Common Substring Bottom Up and Printing Implementation

#include <bits/stdc++.h>
using namespace std;
int main()
{
      string a, b;
      cin >> a >> b;
      int n = a.size(), m = b.size(), i, j;
      int dp[n + 1][m + 1];
      for (i = 0; i <= n; i++)
      {
            for (j = 0; j <= m; j++)
            {
                  if (i == 0 || j == 0)
                        dp[i][j] = 0;
            }
      }
      for (i = 1; i <= n; i++)
      {
            for (j = 1; j <= m; j++)
            {
                  if (a[i - 1] == b[j - 1])
                  {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                  }
                  else
                  {
                        dp[i][j] = 0;
                  }
            }
      }
      int mx = 0;
      int ci, cj;
      for (i = 0; i <= n; i++)
      {
            for (j = 0; j <= m; j++)
            {
                  if (dp[i][j] > mx)
                  {
                        mx = dp[i][j];
                        ci = i;
                        cj = j;
                  }
            }
      }
      cout << mx << endl;
      string s;
      while (ci != 0 && cj != 0)
      {
            if (a[ci - 1] == b[cj - 1])
            {
                  s += a[ci - 1];
                  ci--;
                  cj--;
            }
            else
            {
                  break;
            }
      }
      reverse(s.begin(), s.end());
      cout << s << endl;
      return 0;
}