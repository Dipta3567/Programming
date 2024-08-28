#include <bits/stdc++.h>
using namespace std;
int r, c, cnt;
bool vis[35][35];
char ch[35][35];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    if (i < 0 || i >= r || j < 0 || j >= c)
        return false;
    return true;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + dir[i].first;
        int cj = sj + dir[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && ch[ci][cj] != '#')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    int t, sr, sc;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        memset(vis, false, sizeof(vis));
        cin >> c >> r;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> ch[i][j];
                if (ch[i][j] == '@')
                {
                    sr = i;
                    sc = j;
                }
            }
        }
        cnt = 0;
        dfs(sr, sc);
        cout << "Case " << k << ": " << cnt << endl;
    }
    return 0;
}