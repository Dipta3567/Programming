/*
Types Of Graphs:
    1. Undirected Graph
    2. Directed Graph
    3. Weighted Graph
    4. Unweighted Graph
    5. Cycle
           i.  Undirected Graph er modhe 2 ta node er modhe cyle dore hoi na, minimum 3 ta node lage
           ii. Directed Graph e 2 tar modhe dik dile cyle dora hoi

Graph representation are 3 types:

            1.Adjacency Matrix
            2.Adjancency List
            3.Edge List



*/

#include <bits/stdc++.h>
using namespace std;
int main()
{

    // Adjancency Matrix
    /*
        int n, e;
        cin >> n >> e;
        int mat[n][n];
        memset(mat, 0, sizeof(mat)); // matrix er shob value ke 0 korar jonno
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            mat[a][b] = 1;
            mat[b][a] = 1; // Undirected hole ata use korbo but directed hole use kora jabe na
        }
        if (mat[3][4] == 1)
            cout << "Conected\n";
        else
            cout << "Not Connected\n";
    */

    // Adjancency List
    /*
        int n, e;
        cin >> n >> e;
        vector<int> v[n];
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a); // Undirected hole ata use korbo but directed hole use kora jabe na
        }

        for (int i=0;i<v[0].size();i++)
        cout << v[0][i] << " ";

        for (auto u : v[0])
            cout << u << " ";

    */

    // STL Pair

    pair<int, int> p;
    p = make_pair(10, 20);
    cout << p.first << " " << p.second << endl;

    // Edge List

    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> v;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for (pair<int, int> p : v)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl << endl;
    for (auto p : v)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}