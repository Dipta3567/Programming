/*

Formula :
    (a+b)%c = (a%c + b%c)%c  // Addition
    (a*b)%c = (a%c * b%c)%c  // Multiplication

    (7+3)%3 = 10%3 = 1
    ((7%3) + (3%3))%3 = (1+0)%3 = 1

    example:
        10010101010101010000843303840000066666677654333 %5
       string =n , ch='1'
       int x=ch-'0'
        ans=0
        for (i=0;i<s.size();i++)
        {
            ans=ans*10 + s[i]-'0'
            ans%=m
        }

        if (ans%m == 0)
        cout << "Yes"
        else
        cout << "No"

*/

#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int

void div(string s, int m)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ans = ans * 10 + (s[i] - '0');
        ans%=m;
    }
    if (ans%m)
    cout << "No\n";
    else
    cout << "YES\n";
}

int main()
{
    // optimize();
    ll t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        cin >> s;
        int m;
        cin >> m;
        div(s, m);
    }
    return 0;
}