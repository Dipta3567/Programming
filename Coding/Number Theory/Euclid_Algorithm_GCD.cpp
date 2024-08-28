/*

GCD = Greatest Common Divisor
Example: GCD of 8 and 12 is 4

gcd(a, b) = gcd(b, a%b) = gcd(a%b, b%(a%b)) = gcd(b,0) = ans = b till go on till a%b ! = 0


gcd (10,40) = gcd(40,10) = gcd(10,0) = 10

gcd(13,7)=  gcd(7,4) = gcd(4,3) = gcd(3,1) = gcd(1,0) = 1



*/
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}


int main()
{
    //optimize();
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a >> b;
        cout << gcd(a,b) << endl;

    }
    return 0;
}
