#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
vector<int> v[N];
void dfs(int src)
{
    vis[src] = true;
    for (auto u : v[src])
    {
        if (!vis[u])
        {
            dfs(u);
        }
    }
}

int main()
{
    int n, e;
    memset(vis, false, sizeof(vis));
    cin >> n >> e;
    while (e--)
    {
        int a, b;

        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}