#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>v[N];
bool vis[N];
int dis[N];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    dis[src]=0;
    while (!q.empty())
    {
        int par=q.front();
        q.pop();

        for (auto u : v[par])
        {
            if (!vis[u])
            {
                q.push(u);
                vis[u]=true;
                dis[u]=dis[par]+1;
            }
        }
    }
}
int main()
{
    int n,e;
    cin >> n >>e;
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src,des,cost,cnt=0;
    cin >> src >> des >> cost;
    memset(dis,-1,sizeof(dis));
    memset(vis,false,sizeof(vis));
    bfs(src);
    if (dis[des]!=-1 && dis[des]<=cost*2)
    cout << "YES\n";
    else
    cout << "NO\n";
    
    return 0;
}