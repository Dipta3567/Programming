#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class Edge
{
public:
    ll u, v, c;
    Edge(ll u, ll v, ll c)
    {
        this->u = u;
        this->c = c;
        this->v = v;
    }
};
ll dis[1010];
int main()
{
    ll n, e, i;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    fill(dis, dis + n + 1, 1e18);
    ll s, t;
    cin >> s >> t;
    dis[s] = 0;
    for (i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            ll u = ed.u, v = ed.v, c = ed.c;
            if (dis[u] < 1e18 && dis[u] + c < dis[v])
                dis[v] = dis[u] + c;
        }
    }
    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        ll u = ed.u, v = ed.v, c = ed.c;
        if (dis[u] < 1e18 && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
        cout << "Negative Cycle Detected\n";
    else
    {
        while (t--)
        {
            ll x;
            cin >> x;
            if (dis[x] != 1e18)
                cout << dis[x] << endl;
            else
                cout << "Not Possible\n";
        }
    }
    return 0;
}