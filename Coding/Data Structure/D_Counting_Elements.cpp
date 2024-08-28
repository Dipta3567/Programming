#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    optimize();
    int n,i,cnt=0;
    cin >> n;
    vector<int> v(n), freq(1005,0);
    for (i=0;i<n;i++)
    {
        cin >> v[i];
        freq[v[i]]++;
    }
    for (i=0;i<1004;i++)
    {
        if (freq[i] > 0 && freq[i+1]>0)
        cnt+=freq[i];

    }
    cout << cnt << endl;
    return 0;
}
