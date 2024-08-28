#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, x, t;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        pq.push(x);
    }
    cin >> t;
    while (t--)
    {
        cin >> x;
        if (x == 0)
        {
            cin >> n;
            pq.push(n);
            cout << pq.top() << endl;
        }
        else if (x == 1)
        {
            if (!pq.empty())
            {
                cout << pq.top() << endl;
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
                    cout << pq.top() << endl;
                else
                    cout << "Empty\n";
            }
            else
                cout << "Empty\n";
        }
    }

    return 0;
}