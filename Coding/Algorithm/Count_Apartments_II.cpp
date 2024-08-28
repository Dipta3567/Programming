#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool vis[1010][1010];
vector<int> v;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int r, c, ct;
bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= r || cj < 0 || cj >= c)
        return false;
    return true;
}
void dfs(int sr, int sc)
{
    ct++;
    vis[sr][sc] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = sr + dir[i].first;
        int cj = sc + dir[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    memset(vis, false, sizeof(vis));
    int i, j, cnt = 0;
    cin >> r >> c;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            cin >> a[i][j];
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (vis[i][j] == false && a[i][j] == '.')
            {

                ct = 0;
                dfs(i, j);
                cnt++;
                v.push_back(ct);
            }
        }
    }

    sort(v.begin(), v.end());
    if (v.empty())
        cout << "0\n";
    else
    {
        for (auto u : v)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}