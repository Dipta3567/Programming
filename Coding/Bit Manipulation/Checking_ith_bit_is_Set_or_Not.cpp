/*


let we have a number n = 10 , we have to check if its ith bit is 1 naki.
it can be done by left shif and right shift operation.

Right shift : 
    steps :
            we have to shift it to right by i times and then take the and with 1.

            if the result is 1 then the ith bit is set otherwise not.

 n = n >> i;
 if (n & 1)
    cout << "Set";
 else
    cout << "Not Set";

let n = 10 = 1010 and i = 2
n = 10 >> 2 = 2

32 16 8 4 2 1
0  0  0 0 1 0

now n = 2 = 0010
n & 1 =  10
         01
        ----
         00

            so the ith bit is not set.


now if i = 3

n = 10 >> 3 = 1

32 16 8 4 2 1
0  0  0 0 0 1

now n = 1 = 01
n & 1 =  01
         01
        ----
         01

            so the ith bit is set.


Left shift :

    steps :
            its rule is different from right shift.
            we have to shift 1 only not the whole number.

n = 10 = 1010
i = 2
here we have to shift 1 to left by 2 times.
so we get 100 
now we have to do and with 1 and 10.

n = 1010
1 = 0100   
---------
    0000

    so the ith bit is not set.

n = 10 = 1010
i = 3
here we have to shift 1 to left by 3 times.
    3 2 1 0
n = 1 0 1 0
1 = 1 0 0 0  
---------
    1000

    so the ith bit is set.



*/

// Code :

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

int main()
{
    optimize();
    int n, i;
    cin >> n >> i;
    cout << "Left Shift : ";
    int temp = 1 << i;
    if (n & temp)
        cout << "Set";
    else
        cout << "Not Set";

    cout << "\nRight Shift : ";
    int temp1 = n >> i;
    if (temp1 & 1)
        cout << "Set";
    else
        cout << "Not Set";
    return 0;
}