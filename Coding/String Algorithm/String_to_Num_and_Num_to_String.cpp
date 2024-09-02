// String to Num and Num to String

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

int main()
{
    //optimize();
    
    // String to Num
    string s1 = "123568254";
    int a = stoi(s1); // integer
    cout << a << endl;
    double b = stod(s1); // double
    cout << b << endl;
    ll c = stoll(s1); // long long
    cout << c << endl;
    ull d = stoull(s1); // unsigned long long
    cout << d << endl;

    cout << s1[0]-'0' << endl;

    for (int i = 0; i < s1.size(); i++)
    {
        cout << s1[i]-'0' << " ";
    }
    int x=0;
    for (int i = 0; i < s1.size(); i++)
    {
        x = x*10 + s1[i]-'0';
    }
    cout << x << endl;

    // Num to String

    int e = 123456;
    string s2 = to_string(e);
    cout << s2 << endl;
    string s3;
    while (e)
    {
        s3 += (e%10) + '0';
        e /= 10;
    }
    reverse(s3.begin(), s3.end());
    cout << s3 << endl;


    return 0;
}