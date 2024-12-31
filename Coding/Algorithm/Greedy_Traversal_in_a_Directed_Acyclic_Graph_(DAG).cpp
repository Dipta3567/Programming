#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pi pair<ll, ll> // A pair representing a neighbor node and its associated learning value

const ll N = 105; // Maximum number of nodes in the graph
vector<pi> v[N];  // Adjacency list to store the graph, where each node has a list of neighbors
ll learning[N];   // Array to store the learning value for each node

// Function to simulate the person's journey through the graph using a greedy strategy
pair<ll, ll> greedy_traverse(int n)
{
    ll total_learning = 0; // Total learning units accumulated
    int current = 0;       // Start journey at node 0

    // Continue the journey until no more nodes can be visited
    while (true)
    {
        total_learning += learning[current]; // Add the learning value of the current node
        ll max_value = -1, next_node = -1;   // Variables to track the best next node

        // Iterate over all neighbors of the current node
        for (pi neighbor : v[current])
        {
            // If the neighbor has a higher learning value than the current maximum, update
            if (learning[neighbor.first] > max_value)
            {
                max_value = learning[neighbor.first];
                next_node = neighbor.first; // Choose this neighbor as the next node
            }
        }

        // If no valid next node is found, end the journey
        if (next_node == -1)
            break;

        // Move to the chosen neighbor
        current = next_node;
    }

    // Return the total learning accumulated and the final node where the journey ends
    return {total_learning, current};
}

int main()
{
    optimize(); // Optimize I/O for competitive programming
    ll t;       // Number of test cases
    cin >> t;

    for (ll k = 1; k <= t; k++)
    {
        ll n, m; // Number of nodes and edges in the graph
        cin >> n >> m;

        // Clear the adjacency list for the new test case
        for (int i = 0; i < n; i++)
            v[i].clear();

        // Read the learning values for each node
        for (int i = 0; i < n; i++)
            cin >> learning[i];

        // Read the edges and build the adjacency list
        while (m--)
        {
            ll u, v1; // Edge from node u to node v1
            cin >> u >> v1;
            v[u].push_back({v1, learning[v1]}); // Add v1 as a neighbor of u with its learning value
        }

        // Perform the greedy traversal starting from node 0
        auto [max_learning, final_node] = greedy_traverse(n);

        // Output the result for the current test case
        cout << "Case " << k << ": " << max_learning << " " << final_node << endl;
    }
    return 0;
}
