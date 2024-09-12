/*


array= 3 5 7 9

we have to do us 
3^5 + 3^7 + 3^9 + 5^7 + 5^9 + 7^9 = 48

so the formula is : a0^a1 + a0^a2 + a0^a3 + a1^a2 + a1^a3 + a2^a3 = 48


ata normaly 2 ta loop chalai dile o(n^2) te kora jabe but ata te tle ashte pare

This is a bit manupulation oriblem so we have to use bit manupulation

so let arr= 3 5 9

3= 0011
5= 0101
9= 1001

3^5= 0 1 1 0 = 6
3^9= 1 0 1 0 = 10
5^9= 1 1 0 0 = 12

pos= 3 2 1 0


ans = 6+10+12 = 28

so we have to do is : 

we have to check in the 0 no position how many 1 is there and multiply it it with the (2^ pos) and it countinues

so, 0*(2^0)+ 2*(2^1)+ 2*(2^2)+ 2*(2^3) = 28


so the question is how to find the number of 1 in the 0th position :
                0 th index 
                ----------          in xor we know 
                                        0^1 1^0 = 1
                                        0^0 1^1 = 0
                    0
                    1
                    0
                    1
                   -----  
after xor 1 :    one * zero

this means like : 
    3= 0011
    5= 0101
    9= 1001

    here 0th index we have 3 1 and 0 0 so the answer is 3*0 = 0 *(2^0) = 0
    1th index  er have 1 1 and 2 0 so the answer is 1*2 = 2 *(2^1) = 4
    2th index  er have 1 1 and 2 0 so the answer is 2*1 = 2 *(2^2) = 8
    3th index  er have 1 1 and 2 0 so the answer is 2*1 = 2 *(2^3) = 16
    so 16+ 8 + 4 + 0 = 28

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
    int n;
    cin>>n;
    int arr[n+1],i;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll ans=0,j;
    for(i=0;i<32;i++)
    {
        ll one = 0,zero=0;
        for(j=0;j<n;j++)
        {
            if(arr[j] & (1<<i)) // here we are checking the 0th index how many 1 is there
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        int p=one*zero;
        ans+=(1<<i)*p;
    }
    cout<<ans<<endl;
    return 0;
}