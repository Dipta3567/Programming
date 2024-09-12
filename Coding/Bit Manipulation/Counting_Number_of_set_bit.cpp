/*


we have to count the number of set bits(1) in a given number.

Right shift : 

    let n = 10
    10 = 1010
    cnt = 0
while (n !=0)
{
    if (n & 1 == 1)
        cnt++;
    n = n >> 1;
}
cout << cnt;

Output : 2

Time Complexity : O(logn)

Left shift :

    in this approch we have to see what is the input. if its an integar, then we can say that an integar max size is 10^9 so its max bit is 31. so we can run a loop from 0 to 32 and check if the ith bit is set or not.
    if its a long long int then we can run a loop from 0 to 64.

    n = 10
    cnt = 0
    for (int i = 0; i < 32; i++)
    {
        if (n & (1 << i) != 0)
            cnt++;
    }

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
    int n,x;
    cin >> n;
    x=n;
    int cnt = 0;
    cout << "Right Shift : ";
    while (n != 0)
    {
        if (n & 1 == 1)
            cnt++;
        n = n >> 1;
    }
    cout << cnt << endl; // this is slow

    // fast way
    n=x;
    int ans = 0;
    while (n > 0)
    {
        ans += n % 2;
        n /= 2;
    }
    cout << ans << endl;

    cnt = 0;
    n=x;
    cout << "Left Shift : ";
    for (int i = 0; i < 32; i++)
    {
        if (n & (1 << i) != 0)
            cnt++;
    }
    cout << cnt << endl;
    
    return 0;
}