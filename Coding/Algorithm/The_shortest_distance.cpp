#include <bits/stdc++.h>
using namespace std;
vector<int> v[1010];
bool vis[1010];
int level[1010];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (auto child : v[par])
        {
            if (!vis[child])
            {
                vis[child] = true;
                level[child] = level[par] + 1;
                q.push(child);
            }
        }
    }
}
int main()
{
    int s, n, i, j, x;
    cin >> n >> s;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> x;
            if (x == 1)
                v[i].push_back(j);
        }
    }
    fill(vis, vis + n + 1, false);
    fill(level, level + n + 1, -1);
    bfs(s);
    for (i = 1; i <= n; i++)
        cout << level[i] << " ";
    cout << endl;
    return 0;
}