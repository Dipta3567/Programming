#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
vector<int> v[N];
int parent[N] = {-1}, cnt;
void dfs(int par)
{
    vis[par] = true;
    for (auto child : v[par])
    {
        if (vis[child] && parent[par] != child)
        {
            cnt++;
        }
        if (!vis[child])
        {
            parent[child] = par;
            dfs(child);
        }
    }
}
int main()
{
    int n, e, a, b, i;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));

    cnt = 0;
    for (i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    cout << cnt/2 << endl;
    return 0;
}