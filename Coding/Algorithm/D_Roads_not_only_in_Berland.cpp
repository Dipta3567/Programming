#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int par[N], sz[N];

void dsu_in(int n)
{
    for (int i = 0; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}

int dsu_find(int node)
{
    if (par[node] == node)
        return node;
    return par[node] = dsu_find(par[node]);
}

void dsu_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (sz[leaderA] > sz[leaderB])
    {
        par[leaderB] = leaderA;
        sz[leaderA] += sz[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        sz[leaderB] += sz[leaderA];
    }
}

int main()
{
    int n;
    cin >> n;
    dsu_in(n);
    vector<pair<int, int>> close, build;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (dsu_find(u) == dsu_find(v))
        {
            close.push_back({u, v});
        }
        else
        {
            dsu_size(u, v);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (dsu_find(i) != dsu_find(1))
        {
            build.push_back({1, i});
            dsu_size(1, i);
        }
    }
    cout << close.size() << endl;
    for (int i = 0; i < close.size(); i++)
    {
        cout << close[i].first << " " << close[i].second << " " << build[i].first << " " << build[i].second << endl;
    }
    return 0;
}
