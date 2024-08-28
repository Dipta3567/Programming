#include<bits/stdc++.h>
using namespace std;
vector<int>v[1000];
int main()
{
    int n,e;
    cin >> n >> e;
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int x;
    cin >> x;
    cout << v[x].size() <<endl;
    return 0;
}