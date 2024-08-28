#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000];

bool vis[1000];
int cnt = 0;
void dfs(int src)
{
    cnt++;
    vis[src] = true;
    for (auto child : v[src])
    {
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
}
int main()
{
    int a, b, n, e;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> a;
    cnt=0;
    memset(vis, false, sizeof(vis));
    dfs(a);

    cout << cnt << endl;

    return 0;
}