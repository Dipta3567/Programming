/*

s= s1, s2, s3, s4,s5,........sn ---- string

T= T1, T2, T3 ---- strubg

s er modhe T er jetogula substring ache seta ber korte hobe




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
    string s,t;
    cin >> s;
    cin >> t;
    ll ans=0,i,k;
    string s1;
    for (i=0;i<t.size();i++)
    {
        s1+=t[i];
    }
    if (s1==t)
        ans++;

    for (i=t.size();i<s.size();i++)
    {
        s1+=s[i];
        s1.erase(s1.begin());
        if (s1==t)
            ans++;
    }
    cout << ans << endl;
    return 0;
}


// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/

// My solution

class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.size()<3)
        return 0;
        if (s.size()==3)
        {
            string c;
            c=s;
            sort(c.begin(),c.end());
            string :: iterator end=unique(c.begin(),c.end());
            c.erase(end,c.end());
            if (c.size()==s.size())
            return 1;
            else
            return 0;
        }
        vector<string>v;
        int i,ans=0;
        string cpy;
        for (i=0;i<3;i++)
        {
            cpy+=s[i];
        }
        v.push_back(cpy);
        for (i=3;i<s.size();i++)
        {
            cpy+=s[i];
            cpy.erase(cpy.begin());
            v.push_back(cpy);
        }
        for (auto u : v)
        {
            sort(u.begin(),u.end());

            string :: iterator end=unique(u.begin(),u.end());
            u.erase(end,u.end());
            if (u.size()==3)
            ans++;
        }
        return ans;
    }
};



// Class solution

class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.size()<3)
        return 0;
        map<char,int>mp;
        int i,ans=0,j;
        mp[s[0]]++;
        mp[s[1]]++;
        mp[s[2]]++;
        if (mp.size()==3)
            ans++;
        for (i=3,j=0;i<s.size();i++,j++)
        {
            mp[s[i]]++;
            mp[s[j]]--;
            if (mp[s[j]]==0)
                mp.erase(s[j]);
            if (mp.size()==3)
                ans++;
        }
        return ans;
    }
};




// https://leetcode.com/problems/maximum-average-subarray-i/

// my solution

#define ll long long int
class Solution {
public:
    double findMaxAverage(vector<int>& v, double k) {
        if (v.size()==1)
            return v[0];
        ll i,j;
        double ans=0;
        for (i=0;i<k;i++)
        {
            ans+=v[i];
        }
        if (v.size()==k)
            return ans/k;
        double maximum=ans/k;
        for (i=k,j=0;i<v.size();i++,j++)
        {
            ans+=v[i];
            ans-=v[j];
            double current=ans/k;
            maximum=max(current,maximum);
            if (abs(maximum)<pow(10,-5))
                return maximum;
        }
        return maximum;
    }
};


// class solution

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans,sum=0;
        int i;
        for (i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        ans=sum/k;
        for (i=k;i<nums.size();i++)
        {
            sum+=nums[i];
            sum-=nums[i-k];
            double num=sum/k;
            if (num>ans)
                ans=num;
        }
        return ans;
    }
};