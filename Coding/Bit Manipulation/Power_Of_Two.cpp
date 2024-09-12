/*


we will check if the number is power of 2 or not.

let number is 10
we will check if the number is power of 2 or not.

n = 10

we can check it by following 2 rules:

1st way :

    32      16      8       4       2       1   -> this are all power of 2
    100000  10000   1000    100     10      1   -> in this binary form main thing is there are only 1 set in all the binary form.

        so we can check if the number is power of 2 or not by checking if the number has only 1 set bit or not.

2nd way :

    if we take the number and do and operation with n-1 and find ans is 0 then the number is power of 2.
    example:
    n=8
    if ((8 & 7)==0)
    then 8 is power of 2.



*/

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

int main()
{
    optimize();
    int n,cnt=0,x;
    cin>>n;
    x=n;
    // 1st way
    while (n != 0)
    {
        if (n & 1 == 1)
            cnt++;
        n = n >> 1;
    }
    if (cnt == 1)
        cout << x << " is power of 2" << endl;
    else
        cout << x << " is not power of 2" << endl;

    // 2nd way
    n=x;
    if ((n & (n-1)) ==0)
        cout << x << " is power of 2" << endl;
    else
        cout << x << " is not power of 2" << endl;
        
    return 0;
}