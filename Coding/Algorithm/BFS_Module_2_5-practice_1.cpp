#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];
int level[1005] = {-1};
int parent[1005] = {-1};
void bfs_path(int src)
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
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
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
    int t;
    cin >> t;
    while (t--)
    {
        memset(vis, false, sizeof(vis));
        fill(level, level + 1005, -1);
        fill(parent, parent + 1005, -1);
        int src, des;
        cin >> src >> des;
        bfs_path(src);
        int x = des, f = -1;
        vector<int> path;
        while (x != -1)
        {
            path.push_back(x);
            x = parent[x];
        }
        if (path.front() == des && path.back() == src)
        {
            cout << path.size()-1 << endl;
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}