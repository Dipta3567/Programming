/*

    (a/b)%m = ((a%m)/(b%m))%m  ---- wrong

    (6/2)%5 = ((6%5)/(2%5))%5 = (1/2)%5 = 0%5 = 0 ---- wrong

    correct : 
        (a*(1/b))%m = (a * b^-1)%m  =  (a*(b^m-2))%m
                                        ------------
                                        correct formula
        let b^-1 = x
        
        then, (a*x)%m 
    now according to fermat's little theorem
        
        x^m-1 = 1 mod m
                 it also mean
                        (x^m-1) %m = 1
        x^m-2 = x^-1  // here x^-1 is multiply in 2 sides
                 it also mean
                        (x^m-2) %m = x^-1
        (b^-1)%m = (b^(m-2))%m


    example:
        (6/2)%5 = (6*2^-1)%5 = (6*2^3)%5 = 48%5 = 3
        or
        (6/2)%5 = (6*2^-1)%5 = (6*2^3)%5 = (6 * 8)%5 = ((6%5) * (8%5))%5 = (1*3)%5 = 3%5 = 3



*/

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int

int power(int base,int p,int m)
{
    int res = 1;
    while (p)
    {
        if(p%2)
        {
            res=(res*base)%m;
            p--;
        }
        else
        {
            base=(base*base)%m;
            p/=2;
        }
    }

    return res%m;
}

int main()
{
    //optimize();
    
    int a,b,m;
    cin >> a >> b >> m; // (a/b) % m 
    int x = power(b,m-2,m); // b^m-2
    int ans=(a*x)%m;
    cout << ans << endl;


    return 0;
}