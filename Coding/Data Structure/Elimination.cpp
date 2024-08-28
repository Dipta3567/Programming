#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t, i;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        stack<char> st;
        cin >> s;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                if (!st.empty() && st.top() == '0')
                {
                    st.pop();
                }
                else
                    st.push(s[i]);
            }
            else
                st.push(s[i]);
        }
        if (st.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}