#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void fun(int n)
{
    vector<int>v1(n);
    vector <int> v2(n);
    int i;
    for (i=0;i<n;i++)
    cin >> v1[i];
    for (i=0;i<n;i++)
    cin >> v2[i];
    v2.insert(v2.begin()+n,v1.begin(),v1.end());
    for (auto u : v2)
    cout << u << " ";

}
int main()
{
    optimize();
    int n;
    cin >> n;
    fun(n);
    return 0;
}