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