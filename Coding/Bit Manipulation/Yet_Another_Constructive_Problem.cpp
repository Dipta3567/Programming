
// https://www.codechef.com/START24B/problems/ORANDCON


/*

Given x=13

a= 
b=
c=
----------------
x=  1  1  0  1

now let b=x so

a=   
b=   1  1  0  1
c=   
----------------
x=   1  1  0  1
     3  2  1  0

now in 0th index we have 1 so wwe know 0+1=1 and 1*1=1 so let say a=0 and c=1 so, (a|b)= 0+1=1 and (b|c)=1+1=1 and (c|a)=1+0=1 so (a|b)& (b|c)& (c|a)=(1 & 1 & 1)=1 so we can say that a=0,b=1,c=1 is the answer.

now in 1th index we have 0 in x so we can let both a and c be 0 

now for 2nd and 3rd index we can do as 0th index, result is : 

a=   0  0  0  0
b=   1  1  0  1
c=   1  1  0  1
----------------
x=   1  1  0  1
     3  2  1  0

now a=0 and b=c=x so now b and c become same so we have to change 1 number, so if we assume there is a bit in 4th index then we can change the value of c like : 

a= 0  0  0  0  0
b= 0  1  1  0  1
c= 1  1  1  0  1
----------------
x= 0  1  1  0  1
   4  3  2  1  0

in here a is already 0 and b=x so we can assume the 4th index for both b and x = 0 that way x and b are remain same. Now if we assume c = 1 in 4th index then (a | b) = 0 , (b|c)=1, (c | a)=1 and (a | b) & (b | c) & (c | a) = 0 & 1 & 1 = 0 so we can say that a=0,b=0,c=1 is the answer.

so a=0
b=x
c=x+next power value

for next power value :
    c= log2(x) 
    here x= 13 so log2(13) = 3.7 so we can take 3 as the next power value.
    and
    c=pow(2,c+1)+x; this will give the next power value of x.

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
    ll t,a,b,c;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        a=0,b=x;
        c=log2(x);
        c=pow(2,c+1)+x;
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}