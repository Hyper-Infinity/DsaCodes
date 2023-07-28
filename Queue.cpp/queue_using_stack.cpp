/* <<<<< CODE BY SRP >>>>> */
/* <<<<< SAMARTH >>>>> */
/* <<<<< JAY HIND >>>>> */

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef vector<long long int> vli;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef map<int, int> mi;
typedef multimap<int, int> mmi;
typedef unordered_map<int, int> umi;
typedef set<int> si;
typedef multiset<int> msi;
typedef unordered_set<int> usi;

void insert_at_bottom(stack<int> &s, int val)
{
    // Base case
    if (s.empty())
    {
        s.push(val);
        return;
    }

    // recursive steps.
    int element = s.top();
    s.pop();
    insert_at_bottom(s, val);
    s.push(element);
}

void rev(stack<int> &s)
{
    // Base case
    if (s.empty())
    {
        return;
    }
    
    // recursive steps
    int num = s.top();
    s.pop();
    rev(s);
    insert_at_bottom(s, num);
}

class s_queue_1
{
private:
    stack<int> s;

public:
    void push(int data)
    {
        s.push(data);
    }

    void pop()
    {
        if (s.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            rev(s);
            cout << "Popping element : " << s.top() << endl;
            s.pop();
            rev(s);
            return;
        }
    }

    int front()
    {
        if (s.empty())
        {
            return -1;
        }
        else
        {
            rev(s);
            int f = s.top();
            rev(s);
            return f;
        }
    }

    int back()
    {
        if (s.empty())
        {
            return -1;
        }
        else
        {
            return s.top();
        }
    }

    bool is_empty()
    {
        return s.empty();
    }
};

class s_queue_2
{
private:
    stack<int> s;

public:
    void push(int data)
    {
        insert_at_bottom(s, data);
    }

    void pop()
    {
        if (s.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            cout << "Popping element : " << s.top() << endl;
            s.pop();
            return;
        }
    }

    int front()
    {
        if (s.empty())
        {
            return -1;
        }
        else
        {
            return s.top();
        }
    }

    int back()
    {
        if (s.empty())
        {
            return -1;
        }
        else
        {
            rev(s);
            int f = s.top();
            rev(s);
            return f;
        }
    }

    bool is_empty()
    {
        return s.empty();
    }
};

class s_queue_3
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int data)
    {
        s1.push(data);
    }

    void pop()
    {
        if (s1.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            cout << "Popping element : " << s2.top() << endl;
            s2.pop();

            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            return;
        }
    }

    bool is_empty()
    {
        return s1.empty();
    }

    int front()
    {
        if (s1.empty())
        {
            return -1;
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            int element = s2.top();

            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            return element;
        }
    }

    int back()
    {
        if (s1.empty())
        {
            return -1;
        }
        else
        {
            return s1.top();
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    s_queue_3 q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    cout << "front : " << q1.front() << endl
         << "Back : " << q1.back() << endl;

    q1.pop();

    cout << "front : " << q1.front() << endl
         << "Back : " << q1.back() << endl;

    return 0;
}