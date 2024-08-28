#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vis[N];
vector<int>v[N];
bool path[N];
bool ans;
void dfs(int s)
{
    vis[s]=true;
    path[s]=true;
    for (auto child : v[s])
    {
        if (path[child])
        {
            ans=true;
        }
        if (!vis[child])
        {
            dfs(child);
        }
    }
    path[s]=false;
}
int main()
{
    int n,i,j,x,s;
    cin >> n;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            cin >> x;
            if (x==1)
            v[i].push_back(j);
        }
    }
    memset(vis,false,sizeof(vis));
    memset(path,false,sizeof(path));
    ans=false;
    for (i=1;i<=n;i++)
    {
        if (!vis[i])
        dfs(i);

    }
    if (ans)
    cout << "1\n";
    else
    cout << "0\n";

    return 0;
}