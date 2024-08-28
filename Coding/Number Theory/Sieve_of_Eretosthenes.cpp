/*
Why we need Sieve of Eratosthenes?
-> To find all prime numbers upto a given number.
   Preprocessing Time : O(nlog(log(n)))
   Answering Query Time : O(1)
   Extra Space : O(n)

It works on the principle that all the non-prime numbers are divisible by prime numbers only.
1st it will mark all the multiples of 2 as non-prime, then it will mark all the multiples of 3 as non-prime and so on.

*/
#include<bits/stdc++.h>
using namespace std;


int is_prime[1000001];

void sieve()
{
    int maxN=1000000;
    for(int i=0;i<=maxN;i++)
    {
        is_prime[i]=1;
    }
    is_prime[0]=is_prime[1]=0;

    for(int i=2;i*i<=maxN;i++)
    {
        if(is_prime[i]==1)
        {
            for(int j=i*i;j<=maxN;j+=i) // 
            {
                is_prime[j]=0;
            }
        }
    }
}

int main()
{
    sieve();
    int n;
    cin>>n;
    if(is_prime[n]==1)
    {
        cout<<"Prime"<<endl;
    }
    else
    {
        cout<<"Not Prime"<<endl;
    }
    return 0;
}