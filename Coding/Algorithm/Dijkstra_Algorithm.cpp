#include <bits/stdc++.h>
using namespace std;

// Dijkstra Naive Implementation // complexity = (N*E)

const int N = 100;
vector<pair<int, int>> v[N];
int dis[N];

void dijkstra_naive(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int node = p.first;
        int cost = p.second;
        for (pair<int, int> u : v[node]) // for (auto u : v[node])
        {
            int child_node = u.first;
            int child_cost = u.second;
            if (cost + child_cost < dis[child_node])
            {
                // path relax
                // q.push({child_node,dis[child_node]}); ata age lekle bhul hobe karon cost ta to akono update hoy nai
                dis[child_node] = cost + child_cost;
                q.push({child_node, dis[child_node]});
            }
        }
    }
}

// Dijkstra Optimized Implementation // Complexity = O((V+E)logV) = O(ElogV)

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
};

void dijkstra_optimize(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    ;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int node = p.first;
        int cost = p.second;
        for (pair<int, int> u : v[node]) // for (auto u : v[node])
        {
            int child_node = u.first;
            int child_cost = u.second;
            if (cost + child_cost < dis[child_node])
            {
                // path relax
                // q.push({child_node,dis[child_node]}); ata age lekle bhul hobe karon cost ta to akono update hoy nai
                dis[child_node] = cost + child_cost;
                pq.push({child_node, dis[child_node]});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;
    // dijkstra_naive(0);
    dijkstra_optimize(0);
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}



//---------------------------------------------------------------------------------------------------//



// Dijkstra shortest path printing : https://codeforces.com/problemset/problem/20/C

#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
using namespace std;
const ll N = 1e5 + 5;
vector<pi> v[N];
ll dis[N];
ll parent[N];
class cmp
{
public:
    bool operator()(pi a, pi b)
    {
        return a.second > b.second;
    }
};
void dijkstra(ll s)
{
    priority_queue<pi, vector<pi>, cmp> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty())
    {
        pi par = pq.top();
        pq.pop();
        ll node = par.first;
        ll cost = par.second;
        for (pi child : v[node])
        {
            ll ch_node = child.first;
            ll ch_cost = child.second;
            if (cost + ch_cost < dis[ch_node])
            {
                dis[ch_node] = cost + ch_cost;
                pq.push({ch_node, dis[ch_node]});
                parent[ch_node] = node;
            }
        }
    }
}
int main()
{
    ll a, b, c, n, e;
    cin >> n >> e;
    for (ll i = 0; i <= n; i++)
    {
        dis[i] = 1e18;
        parent[i] = -1;
    }
    while (e--)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    dijkstra(1);
    ll x = n;
    vector<ll> path;
    while (x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }
    if (path.size() == 1)
        cout << -1 << endl;
    else
    {
        reverse(path.begin(), path.end());
        for (auto u : path)
            cout << u << " ";
        cout << endl;
    }

    return 0;
}

/*

Input : Dijkstra Naive Implementation

5 8
0 1 10
0 2 7
0 3 4
1 4 3
2 4 5
2 1 1
3 4 5
3 2 1

*/

/*

problem : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab




#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Create a priority queue to store vertices that
        // are being preprocessed. This is weird syntax in C++.
        // Refer below link for details of this syntax
        // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

        // Create a vector for distances and initialize all
        // distances as infinite (INF)
        vector<int> dist(V, INT_MAX);

        // Insert source itself in priority queue and initialize
        // its distance as 0.
        pq.push(make_pair(0, S));
        dist[S] = 0;

        // Looping till priority queue becomes empty (or all distances are not finalized)
        while (!pq.empty())
        {
            // The first vertex in pair is the minimum distance
            // vertex, extract it from priority queue.
            // vertex label is stored in second of pair (it
            // has to be done this way to keep the vertices
            // sorted distance (distance must be first item
            // in pair)
            int u = pq.top().second;
            pq.pop();

            // 'i' is used to get all adjacent vertices of a vertex
            for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                // Get vertex label and weight of current adjacent
                // of u.
                int v = (*i)[0];
                int weight = (*i)[1];

                //  If there is shorted path to v through u.
                if (dist[v] > dist[u] + weight)
                {
                    // Updating distance of v
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        // Return the shortest distances
        return dist;
    }
};



//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for(int i=0; i<V; i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }

    return 0;
}











problem : https://www.eolymp.com/en/problems/1365


#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
vector<PII> v[MAX];
bool marked[MAX];
int dis[MAX];
class cmp
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        const
    {
        return a.second < b.second;
    }
};

void dijkstra(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({src,0});
    dis[src]=0;

    while (!pq.empty())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        int node=p.first;
        int cost=p.second;;
        for (auto u : v[node])
        {
            int child_node=u.first;
            int child_cost=u.second;
            if (cost + child_cost < dis[child_node])
            {
                dis[child_node]=cost+child_cost;
                pq.push({child_node,dis[child_node]});
            }
        }
    }
}

int main()
{
    int n, s, f, i, j;
    cin >> n >> s >> f;
    s--,f--;

    for (i = 0; i < n; i++)
    {
        for (j=0;j<n;j++)
        {
            int x;
            cin >> x;
            if (x!=-1)
            v[i].push_back({j,x});
        }
    }
    fill(dis,dis+n,INT_MAX);
    dijkstra(s);

    if (dis[f] != INT_MAX)
    cout << dis[f] << endl;
    else
    cout << "-1\n";

    return 0;
}


*/


/*


******************************************   Max DIstance in Dijajtra**********************************************
 ////////////////              BUT IT WILL GET TLE           ///////////////

#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pi pair<ll, ll>

const ll N = 1e5 + 5;
vector<pi> v[N];
ll dis[N];

class cmp
{
public:
    bool operator()(pi a, pi b)
    {
        return a.second > b.second; // Max-heap for maximum distance
    }
};

void dijkstra(int src)
{
    priority_queue<pi, vector<pi>, cmp> pq; // Priority queue for max distance
    pq.push({src, 0});
    dis[src] = 0; // Start from 0 cost at the source

    while (!pq.empty())
    {
        pi p = pq.top();
        pq.pop();
        int node = p.first;
        int cost = p.second;

        for (pi u : v[node])
        {
            int child_node = u.first;
            int child_cost = u.second;

            // Update if the new distance is greater
            if (cost + child_cost > dis[child_node])
            {
                dis[child_node] = cost + child_cost;
                pq.push({child_node, dis[child_node]});
            }
        }
    }
}

int main()
{
    optimize();
    ll t;
    cin >> t;
    cin.ignore(); // Handle trailing newline after t
    for (ll k = 1; k <= t; k++)
    {
        string line;
        getline(cin, line); // Read blank line between test cases
        ll n, e;
        cin >> n >> e;

        // Clear graph and reset distances
        for (int i = 0; i < n; i++)
        {
            v[i].clear();
            dis[i] = LLONG_MIN; // Initialize distances to the minimum
        }

        vector<ll> cost(n);
        for (int i = 0; i < n; i++)
            cin >> cost[i];

        // Input edges and costs
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back({b, cost[b]}); // Edge from a to b with learning cost
        }

        // Run Dijkstra for maximum distance
        dijkstra(0);

        // Find the node with the maximum distance
        ll mx = LLONG_MIN, index = 0;
        for (int i = 0; i < n; i++)
        {
            if (dis[i] > mx)
            {
                mx = dis[i];
                index = i;
            }
        }

        cout << "Case " << k << ": " << mx << " " << index << endl;
    }
    return 0;
}





/////////////////////////////////////   Another Approch  but it giving wa //////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pi pair<ll, ll>

const ll N = 1e5 + 5;
vector<pi> v[N];
ll dis[N];

void dijkstra(int src)
{
    priority_queue<pi> pq; // Max-heap (default comparator)
    pq.push({0, src});     // Push starting node with cost 0
    dis[src] = 0;          // Starting distance is 0

    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();
        //cost = -cost; // Negate back to positive since priority queue stores -cost for max-heap behavior

        // Process neighbors
        for (pi u : v[node])
        {
            int child_node = u.first;
            int child_cost = u.second;

            // Update if we find a larger distance
            if (cost + child_cost > dis[child_node])
            {
                dis[child_node] = cost + child_cost;
                //pq.push({-(cost + child_cost), child_node}); // Push with negated cost
                pq.push({(cost + child_cost), child_node}); 
            }
        }
    }
}

int main()
{
    optimize();
    ll t;
    cin >> t;
    cin.ignore(); // Handle trailing newline after `t`

    for (ll k = 1; k <= t; k++)
    {
        ll n, e;
        cin >> n >> e;

        // Clear graph and initialize distances
        for (int i = 0; i < n; i++)
        {
            v[i].clear();
        }
        fill(dis, dis + n, LLONG_MIN); // Reset `dis` efficiently

        vector<ll> cost(n);
        for (int i = 0; i < n; i++)
            cin >> cost[i];

        // Input edges
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back({b, cost[b]});
        }

        // Run Dijkstra for maximum distance
        dijkstra(0);

        // Find the node with the maximum distance
        ll mx = LLONG_MIN, index = 0;
        for (int i = 0; i < n; i++)
        {
            if (dis[i] > mx)
            {
                mx = dis[i];
                index = i;
            }
        }

        cout << "Case " << k << ": " << mx << " " << index << endl;
    }
    return 0;
}





*/