/*


let array = a1,a2,a3,.....,an

query = 0 1  = atr mane amane arry[0] and array[1] xor korbo
        1 2 = atr mane amane arry[1] and array[2] xor korbo
        1 3 = atr mane amane arry[1] and array[3] and array[3] xor korbo
        2 3 = atr mane amane arry[2] and array[3] xor korbo

amake xor ta o(1) e korte hobe

1st step : amake array er prefix xor ber korte hobe

prefix_xor[2] = array[0] xor array[1] xor array[2]
prefix_xor[3] = array[0] xor array[1] xor array[2] xor array[3]

q = 1 3 = p[3]-p[1-1]

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
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int prefix_xor[n];
    prefix_xor[0] = a[0];
    for(int i=1;i<n;i++)
        prefix_xor[i] = prefix_xor[i-1]^a[i];
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(l==0)
            cout<<prefix_xor[r]<<endl;
        else
            {
                ll x=prefix_xor[r]^prefix_xor[l-1];
                cout<<x<<endl;
            }
    }

    return 0;
}


// https://leetcode.com/problems/xor-queries-of-a-subarray/

#define ll long long int
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<ll>x;
        ll i,j;
        x.push_back(arr[0]);
        for (i=1;i<arr.size();i++)
            x.push_back(arr[i]^x[i-1]);
        vector<int>v;
        for (auto u : queries)
        {
            if (u[0]==0)
                v.push_back(x[u[1]]);
            else
                v.push_back(x[u[1]]^x[u[0]-1]);
        }
        return v;
    }
};