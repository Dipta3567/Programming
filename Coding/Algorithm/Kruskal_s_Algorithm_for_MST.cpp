#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int sz[N];
int level[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
        level[i] = 0;
    }
}
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union_by_size(int node1, int node2)
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
void dsu_union_by_level(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderA] = leaderB;
        level[leaderB]++;
    }
}
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->c = c;
        this->u = u;
        this->v = v;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}
int main()
{
    int n, e, u, v, c;
    cin >> n >> e;
    dsu_initialize(n);
    vector<Edge> edgeList;
    while (e--)
    {
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c));
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
    cout << "\n\n";
    int total_cost=0;
    for (auto ed : edgeList)
    {
        int leaderU=dsu_find(ed.u);
        int leaderV=dsu_find(ed.v);
        if (leaderU == leaderV)
        continue;
        else
        {
            dsu_union_by_size(ed.u,ed.v);
            total_cost+=ed.c;
        }
    }
    cout << total_cost << endl;

    return 0;
}

/*

5 7
0 1 2
0 2 3
0 3 3
3 4 6
2 4 4
2 1 7
1 4 5
*/


/*

problem : https://codeforces.com/problemset/problem/25/D

code :

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int par[N], sz[N];
int sz[N];
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


*/