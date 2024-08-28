#include <bits/stdc++.h>
using namespace std;
int r, c;
bool vis[110][110];
int dis[110][110];
vector<pair<int, int>> dir = {{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= r || cj < 0 || cj >= c)
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

        for (int i = 0; i < 8; i++)
        {
            int ci = a + dir[i].first;
            int cj = b + dir[i].second;
            if (valid(ci, cj) && vis[ci][cj] == false)
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
    int t;
    cin >> t;
    while (t--)
    {
        cin >> r >> c;
        int sr, sc, dr, dc;
        cin >> sr >> sc >> dr >> dc;
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(sr, sc);
        cout << dis[dr][dc] << endl;
    }
    return 0;
}