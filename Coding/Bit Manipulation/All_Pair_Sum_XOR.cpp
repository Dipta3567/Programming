/*


we have an array =a0, a1,a2,a3,........,an

we have to take every pair sum and then take xor of all the pair sum

(a0+a0) ^ (a0+a1) ^ (a0+a2) ^ (a0+a3) ^ ........ ^ (a0+an) ^ (a1+a0) ^ (a1+a1) ^ (a1+a2) ^ (a1+a3) ^ ........ ^ (a1+an) ^ (a2+a0) ^ (a2+a1) ^ (a2+a2) ^ (a2+a3) ^ ........ ^ (a2+an) ^ (a3+a0) ^ (a3+a1) ^ (a3+a2) ^ (a3+a3) ^ ........ ^ (a3+an) ^ ........ ^ (an+a0) ^ (an+a1) ^ (an+a2) ^ (an+a3) ^ ........ ^ (an+an)

example : 

    arr={2,3,5}

    (2+2) ^ (2+3) ^ (2+5) ^ (3+2) ^ (3+3) ^ (3+5) ^ (5+2) ^ (5+3) ^ (5+5)

normaly we can do this by using 2 loops but it will take O(n^2) time complexity but we have to do this in o(n) time complexity

we can see that in this we have (2+2) , (3+3), (5+5) so it means it will do with it self and other thing is (2+3) and (3+2) both are same so we can do this by using only one time
 and in xor we know that 1^1=0 so (2+3) ^ (3+2) = 0 so we just need to do is (2+2) ^ (3+3) ^ (5+5)

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
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]*=2;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans^=arr[i];
    }
    cout<<ans<<endl;
    
    return 0;
}