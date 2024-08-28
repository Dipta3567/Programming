/*
What is binary exponentiation?
-> Binary exponentiation (also known as exponentiation by squaring) is a trick which allows to calculate an using only O(logn) multiplications (instead of O(n) multiplications required by the naive approach).

    In simple words, binary exponentiation allows us to calculate a^n in O(logn) time complexity.
    2^5 =  here 2 is base and 5 is power.
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Naive Approach  time: O(n)

ll naive(ll base, ll power)
{
    ll res = 1;
    for (ll i = 1; i <= power; i++)
        res = res * base;

    return res;
}

/*

Binary Exponentiation  time: O(logn)

2^9=512

res  base  power   
1     2      9

2     2      8       // if  power is odd then multiply res with base and power is reduce by 1 means power-=1
                    //  if power is even then multiply base with base. and divide power by 2.
2     4      4

2     16     2

2     256    1

512   256    0

ans = res = 512
*/


ll binary(ll base, ll power)
{
    ll res = 1;
    while (power > 0)
    {
        if (power % 2 != 0)
        {
            res = res * base;
            power = power - 1;
        }
        else
        {
            base = base * base;
            power = power / 2;
        }
    }
    return res;
}

// if power is greater than 9 then we have to use brute force

ll brute(ll base, ll power, ll mode)
{
    ll res = 1;
    while (power > 0)
    {
        if (power % 2 != 0)
        {
            res = (res * base)%mode;
            power = power - 1;
        }
        else
        {
            base = (base * base)%mode;
            power = power / 2;
        }
    }
    return res;
}


int main()
{
    ll base, power;
    cin >> base >> power;
    cout << naive(base, power) << endl;
    cout << binary(base, power) << endl;
    cout << brute(base, power, 1e9+7) << endl;
    return 0;
}