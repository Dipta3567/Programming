#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000];

bool vis[1000];
int cnt = 0;
void dfs(int src)
{
    
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
    
    memset(vis, false, sizeof(vis));
    cnt=0;
    for (int i=0;i<n;i++)
    {
        if (vis[i]==false)
        {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}