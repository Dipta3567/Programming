#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int sz[N];
void dsu_in(int n)
{
    for (int i=0;i<=n;i++)
    {
        par[i]=-1;
        sz[i]=1;
    }
}
int dsu_find(int node)
{
    if (par[node]==-1)
    return node;
    int leader=dsu_find(par[node]);
    par[node]=leader;
    return leader;
}
void dsu_size(int node1,int node2)
{
    int leaderA=dsu_find(node1);
    int leaderB=dsu_find(node2);
    if (sz[leaderA] > sz[leaderB])
    {
        par[leaderB]=leaderA;
        sz[leaderA]+=sz[leaderB];
    }
    else
    {
        par[leaderA]=leaderB;
        sz[leaderB]+=sz[leaderA];
    }
}
class Edge
{
    public:
    int u,v,c;
    Edge(int u,int v,int c)
    {
        this->c=c;
        this->u=u;
        this->v=v;
    }
};
bool cmp(Edge a,Edge b)
{
    return a.c < b.c;
}
int main()
{
    int n,e;
    cin >> n >> e;
    dsu_in(n);
    vector<Edge>edgeList;
    while (e--)
    {
        int u,v,c;
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u,v,c));
    }
    sort(edgeList.begin(),edgeList.end(),cmp);
    int cost=0;
    for (auto ed : edgeList)
    {
        int leaderU=dsu_find(ed.u);
        int leaderV=dsu_find(ed.v);
        if (leaderU==leaderV)
        continue;
        else
        {
            dsu_size(ed.u,ed.v);
            cost+=ed.c;
        }
    }
    cout << cost << endl;
    return 0;
}