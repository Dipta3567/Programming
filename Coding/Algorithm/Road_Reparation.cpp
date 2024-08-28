#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5;
long long int par[N];
long long int sz[N];
void dsu_in(long long int n)
{
    for (long long int i = 0; i <= n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
    }
}
long long int dsu_find(long long int node)
{
    if (par[node] == -1)
        return node;
    long long int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_size(long long int node1, long long int node2)
{
    long long int leaderA = dsu_find(node1);
    long long int leaderB = dsu_find(node2);
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
class Edge
{
public:
    long long int u, v, c;
    Edge(long long int u, long long int v, long long int c)
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
    long long int n, e;
    cin >> n >> e;
    dsu_in(n);
    vector<Edge> edgeList;
    while (e--)
    {
        long long int u, v, c;
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c));
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
    long long int cost = 0;
    for (auto ed : edgeList)
    {
        long long int leaderU = dsu_find(ed.u);
        long long int leaderV = dsu_find(ed.v);
        if (leaderU == leaderV)
            continue;
        else
        {
            dsu_size(ed.u, ed.v);
            cost += ed.c;
        }
    }
    long long int leader=dsu_find(1);
    for (int i=2;i<=n;i++)
    {
        if (dsu_find(i)!=leader)
        {
            cost=0;
            break;
        }
    }
    if (cost != 0)
        cout << cost << endl;
    else
        cout << "IMPOSSIBLE\n";
    return 0;
}