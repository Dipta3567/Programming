#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 1e5 + 5;
ll par[N];
ll sz[N];
void dsu_initiaze(ll n)
{
    for (ll i = 0; i <= n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
    }
}
ll dsu_find(ll node)
{
    if (par[node] == -1)
        return node;
    ll leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_size(ll node1, ll node2)
{
    ll leaderA = dsu_find(node1);
    ll leaderB = dsu_find(node2);
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
    ll u, v, c;
    Edge(ll u, ll v, ll c)
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
    ll n, e, u, v, c;
    vector<Edge> edgeList;
    cin >> n >> e;
    dsu_initiaze(n);
    while (e--)
    {
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c));
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
    ll cost = 0, leader;
    for (auto ed : edgeList)
    {
        ll leaderU = dsu_find(ed.u);
        ll leaderV = dsu_find(ed.v);
        if (leaderU == leaderV)
            continue;
        else
        {
            dsu_size(ed.u, ed.v);
            cost += ed.c;
        }
    }
    bool ans = true;
    leader = dsu_find(1);
    for (ll i = 1; i <= n; i++)
    {
        if (leader != dsu_find(i))
        {
            ans = false;
            break;
        }
    }
    if (ans)
        cout << cost << endl;
    else
        cout << "-1\n";
    return 0;
}