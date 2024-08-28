#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
using namespace std;
const ll N = 1e5 + 5;
vector<pi> v[N];
ll dis[N];
ll parent[N];
class cmp
{
public:
    bool operator()(pi a, pi b)
    {
        return a.second > b.second;
    }
};
void dijkstra(ll s)
{
    priority_queue<pi, vector<pi>, cmp> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty())
    {
        pi par = pq.top();
        pq.pop();
        ll node = par.first;
        ll cost = par.second;
        for (pi child : v[node])
        {
            ll ch_node = child.first;
            ll ch_cost = child.second;
            if (cost + ch_cost < dis[ch_node])
            {
                dis[ch_node] = cost + ch_cost;
                pq.push({ch_node, dis[ch_node]});
                parent[ch_node] = node;
            }
        }
    }
}
int main()
{
    ll a, b, c, n, e, s, d;
    cin >> n >> e >> s >> d;
    for (ll i = 0; i <= n; i++)
    {
        dis[i] = 1e18;
        parent[i] = -1;
    }
    while (e--)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dijkstra(s);
    vector<ll> path;
    ll x = d;
    while (x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }
    if (path.size() == 1)
        cout << "-1\n";
    else
    {
        reverse(path.begin(), path.end());
        cout << dis[d] << endl; // print the total weight of the shortest path
        for (auto u : path)
            cout << u << " ";
    }
    return 0;
}
