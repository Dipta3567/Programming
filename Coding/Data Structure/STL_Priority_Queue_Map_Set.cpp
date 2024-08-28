#include <bits/stdc++.h>
using namespace std;

/*
// Custom compare class for Priority Queue
class Student
{
public:
    string name;
    int roll, marks;
    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp
{
public:
    bool operator()(Student a, Student b)
    {
        // if (a.marks <= b.marks) // ata marks ke desending  order e sort korbe
        //    return true;        // A er marks choto hole take change kore dan poashe patai dao

        if (a.marks > b.marks) // ata marks ke acsending  order e sort korbe
            return true;       // A er marks boro hole take change kore dan poashe patai dao
        else if (a.marks < b.marks)
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

*/
int main()
{
    
    /*
    // STL Set :  Sorted, unique, search

    set<int>s;  //n(logn)
    int t,x;
    cin >> t;
    while (t--)
    {
        cin >> x;
        s.insert(x);
    }

    if (s.count(10))
    cout << "Found\n";
    else
    cout << "NO\n";

    for (auto it=s.begin();it!=s.end();it++)
    {
        cout << *it << endl;
    }
    
    */
    
    
    
    
    
    
    
    
    
    
    // STL MAP

    // Count Words in a String using Map

    string st="I love cricket He love cricket They love cricket We love football", word;
    //getline(cin, st);
    stringstream ss(st);
    map<string,int>mp;
    while (ss >> word)
    {
        mp[word]++;
    }
    for (auto it=mp.begin();it!=mp.end();it++)
    {
        cout << it->first << " " << it->second << endl; // O(logN)
    }
    

    /*
    map<string,int>mp;
    mp.insert({"Sakib al hasan",75}); // o(logN)
    mp.insert({"Ali mia",45});
    mp.insert({"Kalu mia",89});
    mp["Salman"]=45;
    mp["Rahat"]=78;
    for (auto it=mp.begin();it!=mp.end();it++)
    {
        cout << it->first << " " << it->second << endl; // O(logN)
    }

    if (mp.count("Ali mia"))
    cout << "Ase : " << mp["Ali mia"] << endl;
    else
    cout << "NAI\n";
*/

    /*
    // Custom compare class for Priority Queue
    priority_queue<Student, vector<Student>, cmp> pq;
    int i;
    for (i = 0; i < 5; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student obj(name, roll, marks);
        pq.push(obj);
    }

    cout << endl
         << endl
         << endl
         << "PRINT START : " << endl;
    while (!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        pq.pop();
    }

    */

    /*
    // STL Priority Queue

// Its used for Max heap
        priority_queue<int> pq;

// Its used for Min heap , we can not used () after greater<int> because priority queue used it as a class, if we use () it will become function wich is not supported
        priority_queue<int, vector<int>, greater<int>> pq1;


    while (true)
    {
        int c;
        cin >> c;
        if (c == 0)
        {
            int x;
            cin >> x;
            pq.push(x);
            pq1.push(x);
        }
        else if (c == 1)
        {
            pq.pop();
            pq1.pop();
        }
        else if (c == 2)
        {
            cout << "Max Heap or pq : " << pq.top() << endl;
            cout << "Min Heap or pq1 : " << pq1.top() << endl;
        }
        else if (c == 3)
            break;
    }
    */

    return 0;
}