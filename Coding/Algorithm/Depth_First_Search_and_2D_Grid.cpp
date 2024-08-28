#include <bits/stdc++.h>
using namespace std;

// Depth First Search Implementation

const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
void dfs(int src)
{

    cout << src << " ";
    vis[src] = true;
    for (auto child : v[src])
    {
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
}

// DFS on 2D Grid Implementation

int r, c, i, j, sr, sc;
char a[1000][1000];
bool viss[1000][1000];
vector<pair<int, int>> dir_RLUD = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= r || cj < 0 || cj >= c)
        return false;
    return true;
}

void dfs_grid(int sr, int sc)
{
    cout << sr << " " << sc << endl;
    viss[sr][sc] = true;
    for (i = 0; i < 4; i++)
    {
        int ci = sr + dir_RLUD[i].first;
        int cj = sc + dir_RLUD[i].second;
        if (valid(ci, cj) == true && viss[ci][cj] == false)
        {
            dfs_grid(ci, cj);
        }
    }
}

// 2-d grid problem : https://leetcode.com/problems/number-of-closed-islands/description/

bool isClosedIsland(vector<vector<int>> &grid, int i, int j)
{
    // If we go out of bounds, it's not a closed island
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return false;

    // If we encounter water (1), it's a closed path
    if (grid[i][j] == 1)
        return true;

    // Mark the current cell as visited (water)
    grid[i][j] = 1;

    // perform DFS in all four direction
    bool down = isClosedIsland(grid, i + 1, j);
    bool up = isClosedIsland(grid, i - 1, j);
    bool right = isClosedIsland(grid, i, j + 1);
    bool left = isClosedIsland(grid, i, j - 1);

    // If all directions are closed, it's a closed island
    return down && up && right && left;
}

int closed_Island(vector<vector<int>> &grid)
{
    int count = 0, i, j;
    for (i = 0; i < grid.size(); i++)
    {
        for (j = 0; j < grid[0].size(); j++)
        {
            // If we find land (0), we perform DFS to check if it's a closed island

            if (grid[i][j] == 0)
            {
                // If it is a closed island, increment the count
                if (isClosedIsland(grid, i, j))
                    count++;
            }
        }
    }
    return count;
}

// 2-D grid problem : https://leetcode.com/problems/flood-fill/

class Solution
{
public:
    int x;
    bool vis[100][100] = {false};
    vector<pair<int, int>> dir_RLUD = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool valid(vector<vector<int>> &v, int ci, int cj)
    {
        if (ci < 0 || ci >= v.size() || cj < 0 || cj >= v[0].size())
            return false;
        return true;
    }
    void dfs(vector<vector<int>> &v, int sr, int sc, int c)
    {
        v[sr][sc] = c;
        vis[sr][sc] = true;
        for (int i = 0; i < 4; i++)
        {
            int ci = sr + dir_RLUD[i].first;
            int cj = sc + dir_RLUD[i].second;
            if (valid(v, ci, cj) == true && vis[ci][cj] == false && v[ci][cj] == x)
            {
                dfs(v, ci, cj, c);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &v, int sr, int sc, int c)
    {
        x = v[sr][sc];
        dfs(v, sr, sc, c);
        return v;
    }
};


/*

Problem Statement:

You are given an N x M sized 2D matrix that represents a map of a building. Each cell represents a wall or a
room. The connected rooms are called apartments. Your task is to count the number of apartments in that
building. You can walk left, right, up, and down through the room cells. You can't pass through walls.
Input Format
• The first input line has two integers N and M: the height and width of the map.
• Then there are N lines of M characters describing the map. Each character is either .(room) or #(wall).
Constraints
1.1 <= N , M <= 1000
Output Format
• Output the number of apartments

Sample Input O

5 8
########
#..#...#
####.#.#
#..#...#
########

Sample Output O
3

Sample Input 1

6 8
.#.#####
.#.###..
#..#...#
#.##....
..##.###
#.#.##.#

Sample Output 1

5



code : 


#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool vis[1010][1010];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int r, c;
bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= r || cj < 0 || cj >= c)
        return false;
    return true;
}
void dfs(int sr, int sc)
{
    vis[sr][sc] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = sr + dir[i].first;
        int cj = sc + dir[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    memset(vis, false, sizeof(vis));
    int i, j, cnt = 0;
    cin >> r >> c;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            cin >> a[i][j];
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (vis[i][j] == false && a[i][j] == '.')
            {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}

*/



//----------------------------------------------------------------------------------------------------------------


/*



Problem Statement: 

You will be given a 2D matrix of size  which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(-) means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

The area of a component is the number of dots(.) in that component that can be accessible. You need to tell the minimum area of all available components.

Note: If there are no components, print -1.

Input Format

First line will contain  and .
Next you will be given the 2D matrix.
Constraints

Output Format

Output the minimum area.
Sample Input 0

6 5
..-..
..-..
-----
.-...
.----
.....
Sample Output 0

3
Sample Input 1

3 3
---
---
---
Sample Output 1

-1



code : 



#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool vis[1010][1010];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int r, c;
bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= r || cj < 0 || cj >= c)
        return false;
    return true;
}
int dfs(int sr, int sc)
{
    vis[sr][sc] = true;
    int sz = 1;
    for (int i = 0; i < 4; i++)
    {
        int ci = sr + dir[i].first;
        int cj = sc + dir[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj] == '.')
        {

            sz += dfs(ci, cj);
        }
    }
    return sz;
}
int main()
{
    memset(vis, false, sizeof(vis));
    int i, j;
    cin >> r >> c;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            cin >> a[i][j];
    }
    int sz = INT_MAX;
    bool ans = false;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {

            if (vis[i][j] == false && a[i][j] == '.')
            {
                int x = dfs(i, j);
                ans = true;
                sz = min(x, sz);
            }
        }
    }
    if (ans)
        cout << sz << endl;
    else
        cout << "-1\n";
    return 0;
}






*/

















/*

Road connect problem : https://cses.fi/problemset/task/1666/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];
vector<int> result;

void dfs(int node)
{
    visited[node] = true;
    for (auto u : adj[node])
    {
        if (!visited[u])
        {
            dfs(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; i++)
    {
        if (!visited[i])
        {
            result.push_back(i);
            dfs(i);
        }
    }

    cout << result.size() << "\n";
    for (auto u : result)
    {
        cout << "1 " << u << "\n";
    }

    return 0;
}




*/


// DFS on Components

const int NC = 1e5 + 5;
vector<int> v_C[NC];
bool vis_C[NC];
void dfs_Comp(int src)
{

    cout << src << " ";
    vis_C[src] = true;
    for (auto child : v_C[src])
    {
        if (vis_C[child] == false)
        {
            dfs_Comp(child);
        }
    }
}

int main()
{

    // DFS ON Components : Module 3

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v_C[a].push_back(b);
        v_C[b].push_back(a);
    }

    memset(vis_C, false, sizeof(vis_C));
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis_C[i] == false)
        {
            dfs_Comp(i);
            c++;
        }
    }
    cout << "\nComponents : " << c << endl;

    /*

    // DFS on 2D Grid Implementation

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
    dfs_grid(sr, sc);

    */

    /*

    // Depth First Search Implementation
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    int src;
    cin >> src;
    dfs(src);

    */

    return 0;
}

// Input

/*

// Depth First Search Implementation

6 6
0 1
0 2
0 3
1 4
3 5
3 2
0

// DFS on 2D Grid Implementation

3 4
. . . .
. . . .
. . . .
1 1


// DFS on Components

6 5
0 1
1 2
0 2
3 4
3 5

*/



// https://cses.fi/problemset/task/1666
// code:

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];
vector<int> result;

void dfs(int node)
{
    visited[node] = true;
    for (auto u : adj[node])
    {
        if (!visited[u])
        {
            dfs(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; i++)
    {
        if (!visited[i])
        {
            result.push_back(i);
            dfs(i);
        }
    }

    cout << result.size() << "\n";
    for (auto u : result)
    {
        cout << "1 " << u << "\n";
    }

    return 0;
}
