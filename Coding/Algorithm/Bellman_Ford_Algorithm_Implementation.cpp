#include <bits/stdc++.h>
using namespace std;

// Bellman Ford Algorithm Implementation

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int N = 1e5 + 5;

int dis[N];

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
     // EdgeList.push_back(Edge(v, u, c)); // undirected graph hole ata o use korte hobe
    }
    fill(dis, dis + n, INT_MAX);
    dis[0] = 0;

    for (i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v]) // dis[u]+c < dis[v] && dis[u] < INT_MAX , ata use korle problem korbe karon int max er sathe kisu + korle garbage value ashbe ty problem hobe ty age check kore nibo je ata ki age visit hoyse naki
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    // Detect Negative Cycle using Bellman Ford // n-1 bar loop chalanor por arek bar loop chalai le jodi abr path relax hoi tahole ata negative cycle

    bool cycle = false;

    for (Edge ed : EdgeList)
    {
        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v]) // dis[u]+c < dis[v] && dis[u] < INT_MAX , ata use korle problem korbe karon int max er sathe kisu + korle garbage value ashbe ty problem hobe ty age check kore nibo je ata ki age visit hoyse naki
        {
            cycle = true;
            break;
        }
    }
    cout << endl;
    if (cycle)
        cout << "Cycle found\n";
    else
    {
        for (i = 0; i < n; i++)
            cout << i << "-> " << dis[i] << endl;
    }

    // print
    // for (Edge ed : EdgeList)
    //    cout << ed.u << " " << ed.v << " " << ed.c << endl;

    return 0;
}

/*

input : Bellman Ford Algorithm Implementation  O(V*E)

4 4
0 2 5
0 3 12
2 1 2
1 3 3

4 4
1 3 -3
0 3 5
2 1 1
0 2 -2


Detect Negative Cycle using Bellman Ford

3 3
0 1 -1
1 2 2
2 0 -3

*/
