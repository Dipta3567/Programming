#include <bits/stdc++.h>
using namespace std;
int r, c;
bool vis[35][35];
char ch[35][35];
int dis[35][35];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    if (i < 0 || i >= r || j < 0 || j >= c)
        return false;
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first, b = par.second;
        q.pop();
        if (ch[a][b] == 'E')
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int ci = a + dir[i].first;
            int cj = b + dir[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && ch[ci][cj] != 'T')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}
int main()
{
    int n, si, sj, di, dj;
    memset(vis, false, sizeof(vis));
    cin >> n;
    r = c = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ch[i][j];
            if (ch[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
            else if (ch[i][j] == 'E')
            {
                di = i;
                dj = j;
            }
        }
    }
    bfs(si, sj);
    cout << dis[di][dj] << endl;
    return 0;
}