#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool vis[1010][1010];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int r, c;
bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= r || cj < 0 || cj >= c)
        return false;
    return true;
}
int dfs(int sr, int sc)
{
    vis[sr][sc] = true;
    int sz = 1;
    for (int i = 0; i < 4; i++)
    {
        int ci = sr + dir[i].first;
        int cj = sc + dir[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj] == '.')
        {

            sz += dfs(ci, cj);
        }
    }
    return sz;
}
int main()
{
    memset(vis, false, sizeof(vis));
    int i, j;
    cin >> r >> c;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            cin >> a[i][j];
    }
    int sz = INT_MAX;
    bool ans = false;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {

            if (vis[i][j] == false && a[i][j] == '.')
            {
                int x = dfs(i, j);
                ans = true;
                sz = min(x, sz);
            }
        }
    }
    if (ans)
        cout << sz << endl;
    else
        cout << "-1\n";
    return 0;
}