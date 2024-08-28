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