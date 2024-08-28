#include <bits/stdc++.h>
using namespace std;
class st
{
public:
    string n;
    int v;
    st(string n, int v)
    {
        this->n = n;
        this->v = v;
    }
};
class cmp
{
public:
    bool operator()(st a, st b)
    {
        if (a.n > b.n)
            return true;
        else if (a.n < b.n)
            return false;
        else
        {
            if (a.v < b.v)
                return true;
            else
                return false;
        }
    }
};
int main()
{

    int t;
    cin >> t;
    cin.ignore();
    priority_queue<st, vector<st>, cmp> pq;
    while (t--)
    {
        string s;
        int x;
        cin >> s >> x;
        st obj(s, x);
        pq.push(obj);
    }
    while (!pq.empty())
    {
        cout << pq.top().n << " " << pq.top().v << endl;
        pq.pop();
    }

    return 0;
}