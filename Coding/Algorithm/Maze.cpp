#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char adj[N][N];
bool vis[N][N];
pair<int, int> par[N][N];
int r, c;
vector<pair<int, int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= r || j < 0 || j >= c)
        return false;
    return true;
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
            int ci = parent.first + dir[i].first;
            int cj = parent.second + dir[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && adj[ci][cj] != '#')
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
    cin >> r >> c;
    int i, j, si, sj, di, dj;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            char x;
            cin >> x;
            adj[i][j] = x;
            par[i][j] = {-1, -1};
            if (x == 'R')
            {
                si = i;
                sj = j;
            }
            if (x == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }
    bfs(si, sj);
    if (vis[di][dj])
    {
        int x = di, y = dj;
        while (par[di][dj].first != -1 && par[di][dj].second != -1)
        {
            adj[di][dj] = 'X';
            pair<int, int> s = par[di][dj];
            di = s.first;
            dj = s.second;
        }
        adj[x][y] = 'D';
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << adj[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << adj[i][j];
            }
            cout << endl;
        }
    }
}