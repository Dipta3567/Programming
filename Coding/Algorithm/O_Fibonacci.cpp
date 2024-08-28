#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int fun(int n)
{
    if (n==1 || n==2)
    return n-1;
    int ans=fun(n-1)+fun(n-2);
    return ans;
}
int main()
{
    optimize();
    int n;
    cin >> n;
    cout << fun(n) << endl;
    return 0;
}