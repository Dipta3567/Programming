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
