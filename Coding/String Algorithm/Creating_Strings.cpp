#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

int main()
{
    optimize();
    string st;
    cin>>st;
    set<string> s;
    sort(st.begin(),st.end());
    s.insert(st);
    while (next_permutation(st.begin(),st.end()))
    {
        s.insert(st);
    }
    cout<<s.size()<<endl;
    for (auto u : s)
    {
        cout<<u<<endl;
    }
    
    
    return 0;
}