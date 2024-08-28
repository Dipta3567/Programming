#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
    optimize();
    int t,i,a,b;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        a=b=0;
        string s;
        cin >> s;
        for (i=0;i<s.size();i++)
        {
            if (s[i]=='0')
            a++;
            else
            b++;
        }
        if (a==b && ((a%2==0 && b%2==0) || (a%2!=0 && b%2!=0)))
        cout << "YES" << endl;
        else
        cout << "NO" << endl;


    }
    return 0;
}