#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    optimize();
    int n, i, x;
    cin >> n;
    vector<int> v1(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    cin >> n;
    vector<int> v2(n);
    for (i = 0; i < n; i++)
        cin >> v2[i];
    cin >> x;
    v1.insert(v1.begin() + x, v2.begin(), v2.end());
    for (auto u : v1)
        cout << u << " ";
    return 0;
}