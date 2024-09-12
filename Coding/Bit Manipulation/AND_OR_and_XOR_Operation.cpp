/*

OR operation:

0 + 0 = 0
0 + 1 = 1
1 + 0 = 1
1 + 1 = 1

let's take an example:
     5 | 6 , here | is OR operator

        5 = 101
        6 = 110
       ----------
        7 = 111

    so, 5 | 6 = 7

AND operation:

0 * 0 = 0
0 * 1 = 0
1 * 0 = 0
1 * 1 = 1

let's take an example:
     5 & 6 , here & is AND operator

        5 = 101
        6 = 110
       ----------
        4 = 100

    so, 5 & 6 = 4


XOR operation:

0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0

let's take an example:
     5 ^ 6 , here ^ is XOR operator

        5 = 101
        6 = 110
       ----------
        3 = 011

    so, 5 ^ 6 = 3

    5 ^ 5 = 0

    5 = 101
    5 = 101
    ----------
    0 = 000


*/


// code

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

int main()
{
    optimize();
    int a = 5, b = 6;
    cout << (a | b) << endl; // OR operation
    cout << (a & b) << endl; // AND operation
    cout << (a ^ b) << endl; // XOR operation
    
    return 0;
}