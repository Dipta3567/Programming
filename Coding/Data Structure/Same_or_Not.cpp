#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
    optimize();
    stack<int>st;
    queue<int>q;
    int n,m,i,f=1,x;
    cin >> n >> m;
    for (i=1;i<=n;i++)
    {
        cin >> x;
        st.push(x);
    }
    for (i=1;i<=m;i++)
    {
        cin >> x;
        q.push(x);
    }
    if (n!=m)
    f=0;
    else
    {
        while (!st.empty())
        {
            if (st.top()!=q.front())
            {
                f=0;
                break;
            }
            st.pop();
            q.pop();
        }
    }
    if (f==1)
    cout << "YES" << endl;
    else
    cout << "NO" << endl;
    return 0;
}