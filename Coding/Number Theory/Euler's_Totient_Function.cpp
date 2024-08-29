/*

Euler's Totient Function->

n=10
amake ber korte hobe 1 to 10 er modhe kon kon value er gcd 1 hoi
gcd(1,10)=1
gcd(2,10)=2
........
gcd(10,10)=10


so, 
 gcd(1,10)=1
 gcd(3,10)=1
 gcd(7,10)=1
 gcd(9,10)=1

 akane 1 and 10 co-prime number
 3,10 co-prime number
7,10 co-prime number
9,10 co-prime number
*/

/* #include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007


ll gcd(ll a, ll b)
{
    if (b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}


int main()
{
    optimize();
    ll n,i,j;
    cin>>n;
    ll cnt=0;
    for (i=1;i<=n;i++)
    {
        if (gcd(i,n)==1)
        {
            cnt++;
        }
    }

    cout<<cnt<<endl;

    // atar time complexity onek beshi 
    return 0;
} */

// using Euler's Totient Function
/*


if n = p1^a1 * p2^a2 * p3^a3 * .... * pk^ak , where pi are prime factors of n,

    phi(n) = phi(p1^a1)* phi(p2^a2)*.......phi(pk^ak)

           = (p1^a1 - p1^(a1-1)) * (p2^a2 - p2^(a2-1)) * ....... * (pk^ak - pk^(ak-1))

           = p1^a1 * (1-1/p1) * p2^a2 * (1-1/p2) * .... * pk^ak * (1-1/pk)

           = n* (1-1/p1) * (1-1/p2) * .... * (1-1/pk)

        final formula : phi(n) = n * (1-1/p1) * (1-1/p2) * .... * (1-1/pk)

        where p1,p2,....pk are prime factors of n   


 n = 10
    prime factors of 10 = 2,5

n=60
    prime factors of 60 = 2,2,3,5

    60= 2^2 * 3^1 * 5^1

   n er coprime =  n* (1-1/2) * (1-1/3) * (1-1/5)

   1-1/k= k-1/k

   so  n = n*(2-1/2)*(3-1/3)*(5-1/5) = ans , time = O(sqrt(n))



*/
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

void phi(ll n)
{
    ll i,ans=n;
    
    for (i=2;i*i<=n;i++)
    {
        if (n%i==0)
        {
            ll cnt=0;
            while (n%i==0)
            {
                n/=i;
                cnt++;
            }
            ans*=(i-1);
            ans/=i;
        }
    }
    if (n>1)
    {
        ans*=(n-1);
        ans/=n;
    }
    cout<<ans<<endl;

}


int main()
{
    optimize();
    ll n,i,j;
    cin>>n;
    phi(n);
    return 0;
}