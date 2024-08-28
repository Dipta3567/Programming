#include <bits/stdc++.h>
using namespace std;
class st
{
public:
    string name;
    int roll, mark;
    st(string name, int roll, int mark)
    {
        this->name = name;
        this->mark = mark;
        this->roll = roll;
    }
};
class cmp
{
public:
    bool operator()(st a, st b)
    {
        if (a.mark < b.mark)
            return true;
        else if (a.mark > b.mark)
            return false;
        else
        {
            if (a.roll > b.roll)
                return true;
            else
                return false;
        }
    }
};
int main()
{
    int t, x, mark, roll;
    string s;
    cin >> t;
    cin.ignore();
    priority_queue<st, vector<st>, cmp> pq;
    while (t--)
    {
        cin >> s >> roll >> mark;
        st obj(s, roll, mark);
        pq.push(obj);
    }
    cin >> t;
    while (t--)
    {
        cin >> x;
        if (x == 0)
        {
            cin.ignore();
            cin >> s >> roll >> mark;
            st obj(s, roll, mark);
            pq.push(obj);
            cout << pq.top().name << " " << pq.top().roll << " " << pq.top().mark << endl;
        }
        else if (x == 1)
        {
            if (!pq.empty())
            {
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().mark << endl;
            }
            else
                cout << "Empty\n";
        }
        else if (x == 2)
        {
            if (!pq.empty())
            {
                pq.pop();
                if (!pq.empty())
                {
                    cout << pq.top().name << " " << pq.top().roll << " " << pq.top().mark << endl;
                }
                else
                    cout << "Empty\n";
            }
            else
                cout << "Empty\n";
        }
    }

    return 0;
}