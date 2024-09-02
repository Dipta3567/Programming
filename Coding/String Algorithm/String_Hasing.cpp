/*
 sting hashing is used to convert a string into a unique number.

 hash (s) = s[0] * p^0 + s[1] * p^1 + s[2] * p^2 + ... + s[n-1] * p^(n-1)

 where p is a prime number and s[i] is the ASCII value of the i-th character of the string.

let s= abc
let p = 3
hash (s) = a+3^0 + b*3^1 + c*3^2
          = 97*1 + 98*3 + 99*9
          = 97 + 294 + 891
          = 1282


*/

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007


ll gethash(string s)
{
    int ans=0;
    int p=3;
    int power=1;
    for (int i=0;i<s.size();i++)
    {
        ans=(ans+(s[i]*power))%mod;
        power=(power*p)%mod;
    }
    return ans;
}



int main()
{
    optimize();
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        ll ans= gethash(s);
        cout << ans << endl;
    }
    return 0;
}

