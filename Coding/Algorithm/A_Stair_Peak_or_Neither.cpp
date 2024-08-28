#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    optimize();
    int a,b,c,t;
    cin >> t ;
    while (t--)
    {
        cin >>a >> b >> c;
        if (a < b && b < c && a < c)
        cout << "STAIR\n";
        else if (a < b && b > c)
        cout << "PEAK\n";
        else
        cout << "NONE\n";
    }
    return 0;
}