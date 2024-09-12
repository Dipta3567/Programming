/*


let use consider a number 5
5 = 101 in binary

32 16 8 4 2 1
0  0  0 1 0 1 = 5

Left Shift: 1 time
5 << 1 = 10

32 16 8 4 2 1
0  0  1 0 1 0 = 10

to buja jacce kono number ke left shif korle shob bit bam e ekta ekta kore chole jabe and number barbe

shortcut formula: number * 2^shift
                    5 * 2^1 = 10 HERE 1 IS SHIFT VALUE


Left Shift: 2 time

5 << 2 = 20

32 16 8 4 2 1
0  1  0 1 0 0 = 20

shortcut formula: number * 2^shift
                    5 * 2^2 = 20 HERE 2 IS SHIFT VALUE

Right Shift: 1 time

5 >> 1 = 2

32 16 8 4 2 1
0  0  0 0 1 0 = 2

shortcut formula: number / 2^shift
                    5 / 2^1 = 2 HERE 1 IS SHIFT VALUE

Right Shift: 2 time

5 >> 2 = 1

32 16 8 4 2 1
0  0  0 0 0 1 = 1

shortcut formula: number / 2^shift
                    5 / 2^2 = 1 HERE 2 IS SHIFT VALUE

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
    int n, shift;
    cin>>n>>shift;
    int left_shift = n << shift;
    int right_shift = n >> shift;
    cout<<"Left Shift: "<<left_shift<<endl;
    cout<<"Right Shift: "<<right_shift<<endl;
    
    return 0;
}