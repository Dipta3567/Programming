#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

int main()
{
    //optimize();
    string s;
    cin>>s;
    cout << s.size() << endl;
    sort(s.begin(), s.end());
    cout << s << endl;
    reverse(s.begin(), s.end());
    cout << s << endl;
    cout << s.substr(2, 5) << endl;
    cout << s.find("abc") << endl;
    cout << s.erase(2, 5) << endl;
    getline(cin, s);
    cout << s << endl;
    toupper(s[0]); // shob gula er jonno loop use korte hobe
    cout << s << endl;
    tolower(s[0]);
    
    // isstringstream
    string s1 = "123 456 789";
    stringstream ss(s1);
    int a, b, c;
    ss >> a >> b >> c;
    cout << a << " " << b << " " << c << endl;

    // erase
    string s2 = "abcde";
    s2.erase(2, 2);
    cout << s2 << endl;

    // pop and push
    string s3 = "abcde";
    s3.pop_back();
    cout << s3 << endl;
    s3.push_back('f');
    cout << s3 << endl;
    

    return 0;
}