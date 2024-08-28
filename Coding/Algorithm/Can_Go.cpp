#include <bits/stdc++.h>

using namespace std;

vector<pair<long long int, long long int>> v[1010];
long long int dis[1010];

class cmp
{
public:
    bool operator()(pair<long long int, long long int> a, pair<long long int, long long int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(long long int src)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<long long int, long long int> p = pq.top();
        pq.pop();
        long long int node = p.first;
        long long int cost = p.second;
        for (auto u : v[node])
        {
            long long int cn = u.first;
            long long int cs = u.second;
            if (cost + cs < dis[cn])
            {
                dis[cn] = cost + cs;
                pq.push({cn, dis[cn]});
            }
        }
    }
}

int main()
{
    long long int n, e, i, j, s, d, p, t, k;
    cin >> n >> e;

    while (e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    cin >> s >> t;
    while (t--)
    {
        fill(dis, dis + n + 1, 1e9); 
        dijkstra(s);
        cin >> d >> p;
        if (dis[d] <= p)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
