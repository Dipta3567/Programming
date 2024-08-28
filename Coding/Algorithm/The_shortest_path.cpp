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
                parent[child] = par;
                q.push(child);
            }
        }
    }
}
int main()
{
    int n, e, a, b, s, d;
    cin >> n >> e;
    cin >> s >> d;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int> path;
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    bfs(s);
    while (d != -1)
    {
        path.push_back(d);
        d = parent[d];
    }
    if (path.size() == 1)
        cout << "-1" << endl;
    else
    {
        cout << path.size() - 1 << endl;
        reverse(path.begin(), path.end());
        for (auto u : path)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}