#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

int main()
{
    optimize();
    string s;
    cin>>s;
    while (next_permutation(s.begin(),s.end()))
    {
        cout<<s<<endl;
    }

    vector<int> v = {1,2,3};
    while (next_permutation(v.begin(),v.end()))
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}



// // https://cses.fi/problemset/task/1622

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