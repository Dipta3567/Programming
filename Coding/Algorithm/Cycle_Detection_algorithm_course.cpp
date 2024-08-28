#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
vector<int> v[N];

// Detect Cycle in Undirected Graph using BFS

int parent[N] = {-1};
bool ans;
void bfs_un(int s)
{
    queue<int> q;
    q.push(s);

    vis[s] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl;

        for (auto child : v[par])
        {
            if (vis[child] && parent[par] != child)
            {
                ans = true;
            }
            if (!vis[child])
            {
                vis[child] = true;
                parent[child] = par;
                q.push(child);
            }
        }
    }
}

// Detect Cycle in Undirected Graph using DFS

void dfs_un(int par)
{
    vis[par] = true;
    for (auto child : v[par])
    {
        if (vis[child] && parent[par] != child)
        {
            ans = true;
        }
        if (!vis[child])
        {
            parent[child] = par;
            dfs_un(child);
        }
    }
}


// Detect Cycle in Directed Graph using DFS

bool path_visit[N];
int cnt=0;
void dfs(int s)
{
    vis[s]=true;
    path_visit[s]=true;
    //cout << s << endl;
    for (auto child : v[s])
    {
        
        if (path_visit[child])
        {
            ans=true;
            cnt++;
        }
        if (!vis[child])
        {
            dfs(child);
        }
    }
    path_visit[s]=false;
}



int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        //v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(path_visit,false,sizeof(path_visit));
    ans = false;
    cnt=0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            // bfs_un(i);
            // dfs_un(i);
            dfs(i);
    }
    if (ans)
        cout << "Cycle Found : " << cnt << endl;
    else
        cout << "Cycle Not Found : " << cnt << endl;
    return 0;
}

/*

Detect Cycle in Undirected Graph using BFS

7 6
0 1
1 2
3 4
4 5
5 6
6 3


Detect Cycle in Directed Graph using DFS

7 8
2 1
1 0
0 3
3 1
2 4
4 5
5 6
2 6


7 8
5 6
4 5
0 4
0 6
0 1
1 2
2 3
3 1

*/
