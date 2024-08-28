#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];

// BFS Traversal Implementation
bool vis[1005];
int level[1005] = {-1};
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        cout << par << " ";

        for (auto child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
            }
        }

        /*

        for (auto child : v[par])
        cout << child << " ";

        */

        /*
        for (int i = 0; i < v[par].size(); i++)
        {
            int child = v[par][i];
            cout << child << " ";
        }
        */
    }
}

// BFS level with pair

void bfs_pair(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true;
    bool paisi = false;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int par = p.first;
        int level = p.second;
        if (par == des)
        {
            cout << "Level : " << level << endl;
            paisi = true;
        }
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push({child, level + 1});
                vis[child] = true;
            }
        }
    }
    if (paisi == false)
        cout << "-1" << endl;
}

//  Path Printing using BFS Implementation
/*
6 7
0 1
1 2
1 3
2 4
2 5
4 5
4 3
0
5
*/
int parent[1005] = {-1};
void bfs_path(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (auto child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}

// Path printing problem for 2d matrix: https://www.eolymp.com/en/problems/1060

/*

In the table with n rows and n columns, some cells are occupied with balls, others are free. You choose a ball and a place where you want to move it. In one step the ball can be moved to the next horizontal or vertical empty cell. Determine, is it possible to move the ball from the initial cell to the given, and if it is possible, find a way with the minimum number of steps.

Input data
The first line contains integer n (2 ≤ n ≤ 40), each of the the next n lines contains n symbols. The empty cell is marked with a point, the ball on the table is marked with letter O, the initial position of a ball that must be moved - with @, and the place where the ball must be moved - with a letter X.

Output data
Print Y in the first line , if the path from the start to the end exists, or N otherwise. If the path exists, print N rows with N symbols like it is given at input, but symbol X and all points on the route must be changed to pluses.

Examples
Input example #1 content_copy
5
....X
.OOOO
.....
OOOO.
@....
Output example #1 content_copy
Y
+++++
+OOOO
+++++
OOOO+
@++++
Input example #2 content_copy
5
..X..
.....
OOOOO
.....
..@..
Output example #2 content_copy
N
Input example #3 content_copy
5
...X.
.....
O.OOO
.....
....@
Output example #3 content_copy
Y
..++.
.++..
O+OOO
.++++
....@




code :



#include <bits/stdc++.h>
using namespace std;

const int N = 41;
char adj[N][N];
bool vis[N][N];
pair<int, int> par[N][N];
int n;
vector<pair<int, int>> d = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] && adj[i][j] != 'O';
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = parent.first + d[i].first;
            int cj = parent.second + d[i].second;
            if (valid(ci, cj))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                par[ci][cj] = {parent.first, parent.second};
            }
        }
    }
}

int main()
{
    cin >> n;
    int si, sj;
    int di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            adj[i][j] = x;
            par[i][j] = {-1, -1};
            if (x == '@')
            {
                si = i;
                sj = j;
            }
            if (x == 'X')
            {
                di = i;
                dj = j;
            }
        }
    }

    bfs(si, sj);

    if (vis[di][dj])
    {
        cout << "Y" << endl;

        while (par[di][dj].first != -1 && par[di][dj].second != -1)
        {
            adj[di][dj] = '+';
            pair<int, int> s = par[di][dj];
            di = s.first;
            dj = s.second;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << "N" << endl;
    }

    return 0;
}


*/

// BFS on 2D Grid Implementation

int r, c, i, j, sr, sc;
bool viss[1000][1000];
int dis[1000][1000];
char a[1000][1000];
vector<pair<int, int>> dir_RLUD = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= r || cj < 0 || cj >= c)
        return false;
    return true;
}

void bfs_grid(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    viss[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first, b = par.second;
        q.pop();

        cout << a << " " << b << endl;
        for (i = 0; i < 4; i++)
        {
            int ci = a + dir_RLUD[i].first;
            int cj = b + dir_RLUD[i].second;
            if (valid(ci, cj) == true && viss[ci][cj] == false)
            {
                q.push({ci, cj});
                viss[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}

/*


// 2-d grid with path direction print problem  : https://cses.fi/problemset/task/1193/



#include <bits/stdc++.h>
using namespace std;
bool vis[1005][1005];
char mtx[1005][1005];
pair<int, int> par[1005][1005];

int n, m;
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int main()
{
    int ai, aj, bi, bj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
            par[i][j] = {-1, -1};
            cin >> mtx[i][j];
            if (mtx[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            if (mtx[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
        }
    }

    bool flag = false;
    vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    q.push({ai, aj});
    vis[ai][aj] = true;
    while (!q.empty())
    {
        int si = q.front().first;
        int sj = q.front().second;
        q.pop();
        if (mtx[si][sj] == 'B')
        {
            flag = true;
        }
        for (pair<int, int> x : d)
        {
            int ci = si + x.first;
            int cj = sj + x.second;
            if (valid(ci, cj) && !vis[ci][cj] && mtx[ci][cj] != '#')
            {
                q.push({ci, cj});
                par[ci][cj] = {si, sj};
                vis[ci][cj] = true;
            }
        }
    }
    if (!flag)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<char> v;
    int cnt = 0;

    pair<int, int> selected_node = {bi, bj};
    while (true)
    {
        int x = selected_node.first;
        int y = selected_node.second;
        int x1 = par[x][y].first;
        int y1 = par[x][y].second;
        if (x > x1 && y == y1)
        {
            v.push_back('D');
        }
        else if (x < x1 && y == y1)
        {
            v.push_back('U');
        }
        else if (y > y1 && x == x1)
        {
            v.push_back('R');
        }
        else if (y < y1 && x == x1)
        {
            v.push_back('L');
        }
        if (x1 == ai && y1 == aj)
        {
            break;
        }

        selected_node = par[x][y];
    }
    reverse(v.begin(), v.end());
    cout << v.size() << endl;
    for (char ch : v)
    {
        cout << ch;
    }

    return 0;
}


*/

// 2-d grid problem : https://leetcode.com/problems/number-of-closed-islands/description/

bool isClosedIsland(vector<vector<int>> &grid, int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    bool isClosed = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int x = par.first, y = par.second;
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
        {
            isClosed = false;
            continue;
        }
        if (grid[i][j] == 1)
            continue;

        grid[x][y] = 1;

        q.push({x - 1, y}); // up
        q.push({x + 1, y}); // down
        q.push({x, y + 1}); // right
        q.push({x, y - 1}); // left
    }
    return isClosed;
}

int closedIsland(vector<vector<int>> &grid)
{
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0)
            {
                if (isClosedIsland(grid, i, j))
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{

    // BFS on 2D Grid Implementation

    cin >> r >> c;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }

    cin >> sr >> sc;
    cout << endl;

    memset(viss, false, sizeof(viss));
    memset(dis, -1, sizeof(dis));

    bfs_grid(sr, sc);
    cout << endl
         << endl;

    cout << dis[2][3] << endl;

    /*

    Input:

    3 4
   . . . .
   . . . .
   . . . .
   1 1


    */

    /*

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src, des;
    cin >> src >> des;

    memset(vis, false, sizeof(vis));

    // bfs(src);
    cout << endl
         << endl;
    // for (int i = 0; i < n; i++)
    //   cout << i << " " << level[i] << endl;

    // bfs_pair(src,9);
    bfs_path(src);
    int x = des;
    vector<int> path;
    while (x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }
    reverse(path.begin(), path.end());
    for (auto u : path)
        cout << u << " ";
    cout << endl;

    */

    return 0;
}

/*
7 8
0 1
1 2
0 4
1 3
2 0
3 4
1 5
3 6
0


*/

/*

problem : https://lightoj.com/problem/commandos


code :


#include <bits/stdc++.h>
using namespace std;

vector<bool> vis; // Vector to keep track of visited nodes during BFS
vector<int> dis_from_s, dis_from_d; // Vectors to store distances from source and destination nodes
vector<vector<int>> graph; // 2D vector representing the graph

void bfs(int node, vector<int>& dis)
{
    queue<int> q;
    vis[node] = true; // Mark the starting node as visited
    q.push(node); // Add it to the queue

    while (!q.empty())
    {
        int u = q.front(); // Get the front node from the queue
        q.pop();

        for (auto v : graph[u]) // Explore neighbors of u
        {
            if (!vis[v]) // If v is not visited
            {
                vis[v] = true; // Mark v as visited
                dis[v] = dis[u] + 1; // Update distance from the source
                q.push(v); // Add v to the queue for further exploration
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); // Fast I/O
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t; // Read the number of test cases

    for (int cs = 1; cs <= t; cs++)
    {
        int n, r, s, d, ans = 0;
        cin >> n >> r; // Read the number of nodes and edges

        vis.assign(n, false); // Initialize the visited array
        dis_from_s.assign(n, 0); // Initialize distances from the source
        dis_from_d.assign(n, 0); // Initialize distances from the destination
        graph.assign(n, vector<int>()); // Initialize the graph

        for (int i = 0; i < r; i++)
        {
            int u, v;
            cin >> u >> v; // Read an edge (u, v)
            graph[u].push_back(v); // Add v to u's adjacency list
            graph[v].push_back(u); // Add u to v's adjacency list
        }

        cin >> s >> d; // Read the source and destination nodes
        bfs(s, dis_from_s); // Run BFS from the source
        fill(vis.begin(), vis.end(), false); // Reset visited array
        bfs(d, dis_from_d); // Run BFS from the destination

        for (int i = 0; i < n; i++)
            ans = max(ans, dis_from_s[i] + dis_from_d[i]); // Calculate maximum distance

        cout << "Case " << cs << ": " << ans << "\n"; // Print the result for this test case
    }

    return 0;
}




*/