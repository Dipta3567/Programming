#include <bits/stdc++.h>
using namespace std;
/*
1. What is primality test ?
    A primality test is an algorithm for determining whether an input number is prime. Among other fields of mathematics, it is used for cryptography.

*/

// Naive Approach ..... Time -> O(n)

bool isPrime(int n)
{
    if (n == 1)
        return false;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Better Approch

/*
All divisors of a number N occur in pairs of (a,b) --- > a*b=N

example : 12 has following divisors
    d=1,2,3,4,6,12

pairs are : (1,12), (2,6), (3,4)

Claim :  for a divisor pair (a,b) one of them lies bellow sqrt(N) and other lies above sqrt(N).
    proof:
        There would be 3 cases
        case 1 : Both a and b are below sqrt(N)
        case 2 : Both a and b are above sqrt(N)
        case 3 : one is below and one is above sqrt(N)

Case 1 :
    Let assume that this statement is true, hence
    a < sqrt(N)   b < sqrt(N)
    But then       a*b < N
    which contradicts the fact that a*b = N
    Hence, Case 1 is not True

case 2:
    Let assume that this statement is true, hence
    a > sqrt(N)   b > sqrt(N)
    But then       a*b > N
    which contradicts the fact that a*b = N
    Hence, Case 2 is not True

case 3:
    a=sqrt(N) * sqrt(N)/b  ..... eq(1)

    subCase1:
        b<sqrt(n)  gives  1<sqrt(N)/b
        a=sqrt(N)*(1+x)
        Hence a > sqrt(N)

    subCase2:
        b>sqrt(n)  gives  1>sqrt(N)/b
        a=sqrt(N)*(1-x)
        Hence a < sqrt(N)
*/

bool isPrimeBetter(int n)   // Time -> O(sqrt(n))
{
    if (n == 1)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    if (isPrimeBetter(15))
    cout << "Prime\n";
    else 
    cout << "No\n";
}




