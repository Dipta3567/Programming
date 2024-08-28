#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];
vector<int> result;

void dfs(int node)
{
    visited[node] = true;
    for (auto u : adj[node])
    {
        if (!visited[u])
        {
            dfs(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; i++)
    {
        if (!visited[i])
        {
            result.push_back(i);
            dfs(i);
        }
    }

    cout << result.size() << "\n";
    for (auto u : result)
    {
        cout << "1 " << u << "\n";
    }

    return 0;
}
