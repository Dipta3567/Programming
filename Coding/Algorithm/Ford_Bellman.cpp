#include <bits/stdc++.h>
using namespace std;

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

int dis[110];

int main()
{
    int n, e, i;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    fill(dis, dis + n + 1, 30000);
    dis[1] = 0;

    for (i = 1; i <= n; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u = ed.u, v = ed.v, c = ed.c;
            if (dis[u] < 30000 && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }

    return 0;
}
