#include <bits/stdc++.h>
using namespace std;
// DSU Implementation

const int N = 1e5 + 5;
int par[N];
int sz[N];
int level[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
        level[i] = 0;
    }
}
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (sz[leaderA] > sz[leaderB])
    {
        par[leaderB] = leaderA;
        sz[leaderA] += sz[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        sz[leaderB] += sz[leaderA];
    }
}
void dsu_union_by_level(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderA] = leaderB;
        level[leaderB]++;
    }
}

// Cycle Detection using DSU Implementation
/*

    -> dsu_initialize
    -> dsu_find
    -> dsu_union_by_size

*/

int main()
{
    /*
     // DSU Implementation

     dsu_initialize(8);
     dsu_union_by_level(1,2);
     dsu_union_by_level(2,3);
     dsu_union_by_level(4,5);
     dsu_union_by_level(5,6);
     dsu_union_by_level(1,4);
     cout << endl << endl;
     cout << "Leader of 1 : " << dsu_find(1) << endl;
     cout << "Leader of 4 : " << dsu_find(4) << endl;
     cout << endl << sz[1] << endl;
     */

    // Cycle Detection using DSU Implementation

    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    bool cycle = false;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
            cycle = true;
        else
            dsu_union_by_size(a, b);
    }
    if (cycle)
        cout << "Cycle Found\n";
    else
        cout << "Cycle Not Found\n";
    return 0;
}

// https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int sz[N];
void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
    }
}
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (sz[leaderA] > sz[leaderB])
    {
        par[leaderB] = leaderA;
        sz[leaderA] += sz[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        sz[leaderB] += sz[leaderA];
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA != leaderB)
        {
            dsu_union_by_size(a, b);
        }
    }
    vector<int> leader;
    for (int i = 1; i <= n; i++)
    {
        leader.push_back(dsu_find(i));
    }
    sort(leader.begin(), leader.end());
    leader.erase(unique(leader.begin(), leader.end()), leader.end());
    cout << leader.size() - 1 << endl;
    for (int i = 0; i < leader.size() - 1; i++)
    {
        cout << leader[i] << " " << leader[i + 1] << endl;
    }

    return 0;
}

/*

problem : https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++)
            a[i]=i;
        int k;
        cin>>k;
        for(int i=0;i<k;i++){
            string s;
            cin>>s;
            if(s=="UNION"){
                int z,x;
                cin>>x>>z;
                unionSet(a,x,z);
            }
            else{
                int x;
                cin>>x;
                int parent=find(a,x);
                cout<<parent<<" ";
            }
        }
        cout<<endl;
    }
}
// } Driver Code Ends


// Complete the functions below
int find(int A[],int X)
{
    if(A[X] == X)
        return X;
    else
        return A[X] = find(A, A[X]); // Path compression
}
void unionSet(int A[],int X,int Z)
{
    int leaderX = find(A, X);
    int leaderZ = find(A, Z);

    if(leaderX != leaderZ) {
        A[leaderX] = leaderZ; // Make leader of z as the parent of leader of x
    }
}

*/

/*

// Cycle Detection using DSU Implementation

6 6
0 1
0 2
0 3
3 4
3 5
4 5

*/

/*

cycle detection problem : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  static const int N=1e5+5;
  int par[N];
  int sz[N];
    void dsu_in(int n)
    {
        for (int i=0;i<n;i++)
        {
            par[i]=-1;
            sz[i]=1;
        }
    }
    int dsu_find(int node)
    {
        if (par[node]==-1)
        return node;
        int leader=dsu_find(par[node]);
        par[node]=leader;
        return leader;
    }
    void dsu_size(int node1,int node2)
    {
        int leaderA=dsu_find(node1);
        int leaderB=dsu_find(node2);
        if (sz[leaderA] > sz[leaderB])
        {
            par[leaderB]=leaderA;
            sz[leaderA]+=sz[leaderB];
        }
        else
        {
            par[leaderA]=leaderB;
            sz[leaderB]+=sz[leaderA];
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
    dsu_in(V);
    for (int i=0;i<V;i++)
    {
        for (auto u : adj[i])
        {
            if (i < u) // only consider edges from node i to node u where i < u
            {
                int leaderA=dsu_find(i);
                int leaderB=dsu_find(u);
                if (leaderA==leaderB)
                    return true;
                else
                    dsu_size(i,u);
            }
        }
    }
    return false;
}

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends

*/



/*

There are n people in a certain village. Each of them contains some amount of money. One day a wise person told them to distribute the money such that everyone has equal amount of money. If they can do so, they will be favored by their fortunes.

You are given the information about the money of each person and some relations. Each relation is of the form u v. That means person u and v are capable of making money transactions. They are allowed to use transactions any number of times but they have to do integer transactions only.

Now your task is to answer whether they can redistribute the money such that each of them contains exactly same of money.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case starts with a line containing an integer n (2 ≤ n ≤ 1000) and m (0 ≤ m ≤ 10000) where m denotes the number of relations. The next line contains n space separated integers ranging from 0 to 1000. The ith integer of this line denotes the money for the ith person. Each of the next m lines contains two integers u v (1 ≤ u, v ≤ n, u ≠ v) meaning that person u and v can make transactions. No relation is reported more than once.

Output
For each case, print the case number and Yes if they can equalize their money or No otherwise.

Sample
Inputcopy	Outputcopy
3
5 4
1 0 1 1 2
1 2
2 3
3 4
4 5
2 1
5 10
1 2
4 2
1 1 0 2
1 2
2 3
Case 1: Yes
Case 2: No
Case 3: No
Note
Dataset is huge, use faster I/O methods.



code : 


#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

const int N = 1e5 + 5; // Maximum number of nodes (size of arrays). Chosen to accommodate up to 100,000 nodes.

// Arrays for the Disjoint Set Union (DSU)
int par[N];  // Stores the parent of each node. Used for tracking connected components.
int sz[N];   // Stores the size of each connected component (number of nodes in the component).
int money[N]; // Stores the amount of money associated with each node.

// Initialize the DSU for 'n' nodes
void init(int n)
{
    for (int i = 0; i < n; ++i)
    {
        par[i] = i;  // Initially, each node is its own parent (each node is its own component).
        sz[i] = 1;   // Each component initially has only one node.
    }
}

// Find operation with path compression
int find(int x)
{
    if (par[x] == x) // If 'x' is its own parent, it is the root of its component.
    {
        return x;
    }
    return par[x] = find(par[x]); // Recursively find the root, and compress the path by pointing 'x' directly to the root.
}

// Merge (union) two components
void merge(int a, int b)
{
    int pa = find(a); // Find the root of the component containing 'a'.
    int pb = find(b); // Find the root of the component containing 'b'.

    if (pa != pb) // Only merge if 'a' and 'b' are in different components.
    {
        // Merge the smaller component into the larger one (size-based union).
        if (sz[pa] > sz[pb])
        {
            par[pb] = pa;           // Make 'pa' the parent of 'pb'.
            sz[pa] += sz[pb];       // Update the size of the new component.
            money[pa] += money[pb]; // Combine the money of both components.
        }
        else
        {
            par[pa] = pb;           // Make 'pb' the parent of 'pa'.
            sz[pb] += sz[pa];       // Update the size of the new component.
            money[pb] += money[pa]; // Combine the money of both components.
        }
    }
}

// Check if the money can be evenly distributed among all nodes in each connected component
bool canEqualize(int n, vector<pair<int, int>> &edges)
{
    init(n); // Initialize DSU for 'n' nodes.

    // Merge nodes based on the given edges
    for (auto &edge : edges)
    {
        int u = edge.first, v = edge.second;
        merge(u, v); // Connect nodes 'u' and 'v'.
    }

    // Check each node to ensure the money in its component is evenly divisible by the number of nodes in the component.
    for (int i = 0; i < n; ++i)
    {
        int root = find(i); // Find the root of the component containing node 'i'.
        if (money[root] % sz[root] != 0) // If total money is not divisible by the size, return false.
        {
            return false;
        }
    }

    return true; // All components satisfy the condition.
}

int main()
{
    optimize(); // Optimize input/output operations for competitive programming.
    int t; // Number of test cases.
    cin >> t;

    while (t--)
    {
        int n, m; // Number of nodes and edges in the graph.
        cin >> n >> m;

        // Input the money associated with each node.
        for (int i = 0; i < n; ++i)
        {
            cin >> money[i];
        }

        vector<pair<int, int>> edges; // To store the edges of the graph.
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            u--, v--; // Convert to 0-based indexing for easier array access.
            edges.push_back({u, v}); // Store the edge.
        }

        // Check if money can be equalized among the components and output the result.
        if (canEqualize(n, edges))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}



*/