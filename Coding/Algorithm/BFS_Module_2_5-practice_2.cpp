#include <bits/stdc++.h>
using namespace std;
bool vis[1000];
int level[1000] = {-1};
vector<int> v[1000];
vector<int> path;
void bfs(int l)
{
    queue<int> q;
    q.push(0);
    vis[0] = true;
    level[0] = 0;
    if (l == level[0])
        path.push_back(0);
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (auto child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                if (l == level[child])
                    path.push_back(child);
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    int l;
    cin >> l;
    bfs(l);
    reverse(path.begin(), path.end());
    for (auto u : path)
        cout << u << " ";

    return 0;
}