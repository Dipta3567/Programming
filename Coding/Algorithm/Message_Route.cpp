#include <bits/stdc++.h>
using namespace std;
static const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
int parent[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (auto child : v[par])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
                parent[child] = par;
            }
        }
    }
}
int main()
{

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    int r, c, i;
    cin >> r >> c;
    while (c--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    vector<int> path;
    while (r != -1)
    {
        path.push_back(r);
        r = parent[r];
    }
    if (path.size() == 1)
        cout << "IMPOSSIBLE\n";
    else
    {
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (auto u : path)
            cout << u << " ";
        cout << endl;
    }

    return 0;
}