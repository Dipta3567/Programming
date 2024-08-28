/*

Fibonacci : 0 1 1 2 3 5 8 13

a=0
b=1
i=2,n=5
while (i<=n)
{
    sum=a+b
    a=b
    b=sum
    i++;
}

its O(n) so its not better

now using matrix exponentiation :  O(logn)

[a0 a1] *  [x y]
         [x1 y1]

akon a3 er jonno : 

[a0 a1] *  [x 1]  = [  a2]
          [x1 1]

a4 : 

[a0 a1] *  [0 1]  = [ a1 a2] * M = [a2, a3] *m =[a3, a4]
           [1 1]

so a100= 100 -1= 99 bar power korbo


*/
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define N 5
#define mod 1000000007
ll I[N][N],T[N][N]; // I = identity matrix = result, T = transformation matrix = base matrix

void mul(ll A[][N], ll B[][N], ll dim)
{
    ll res[dim+1][dim+1];
    for (ll i=0;i<dim;i++)
    {
        for (ll j=0;j<dim;j++)
        {
            res[i][j]=0;
            for (ll k=0;k<dim;k++)
            {
                ll x=(A[i][k]*B[k][j]);
                res[i][j]=(res[i][j]+x);
                
                //ll x=(A[i][k]*B[k][j])%mod;
                //res[i][j]=(res[i][j]+x)%mod;
            }
        }
    }

    for (ll i=0;i<dim;i++)
    {
        for (ll j=0;j<dim;j++)
        {
            A[i][j]=res[i][j];
        }
    }
}

void solve(ll a, ll b, ll n)
{
    I[0][0]=I[1][1]=1;
    I[0][1]=I[1][0]=0;

    T[0][0]=0;
    T[0][1]=T[1][0]=T[1][1]=1;

    n--;
    while (n)
    {
        if (n%2)
        {
            mul(I,T,2);
            n--;
        }
        else
        {
            mul(T,T,2);
            n/=2;
        }

    }

    ll ans=a*I[0][1]+b*I[1][1];

    cout << ans << endl;
    //cout << ans%mod << endl;
}



int main()
{
    //optimize();
    
    ll t;
    cin >> t; // test case
    while (t--)
    {
        ll a,b,c;
        cin >> a >> b >> c; // a = a0, b = a1 , c = n th position
        solve(a,b,c);

    }

    return 0;
}