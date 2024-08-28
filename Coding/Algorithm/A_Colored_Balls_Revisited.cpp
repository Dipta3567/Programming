#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define new '\n'
int main()
{
    optimize();
    long long int t,n;  
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long int arr[n],cpy[n],i;
        for (i=0;i<n;i++)
        {
            cin >> arr[i];
            cpy[i]=arr[i];
        }
        sort (cpy, cpy+n);
        if (n==1)
        cout << "1" << new;
        else
        {
            for (i=0;i<n;i++)
            {
                if (cpy[n-1]==arr[i])
                {
                    cout << i+1 << new;
                    break;
                }
            }
        }
    }
    return 0;
}