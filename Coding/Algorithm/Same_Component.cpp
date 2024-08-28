#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool vis[1010][1010];
int r, c, di, dj;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool ans = false;
bool valid(int x, int y)
{
    if (x < 0 || x >= r || y < 0 || y >= c || a[x][y]=='-')
        return false;
    return true;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + dir[i].first;
        int cj = sj + dir[i].second;
        if (valid(ci, cj) && vis[ci][cj] == false && a[ci][cj] == '.')
        {
            if (ci == di && cj == dj)
                ans = true;
            dfs(ci, cj);
        }
    }
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
    int si, sj;
    cin >> si >> sj >> di >> dj;
    ans = false;
    dfs(si, sj);
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}