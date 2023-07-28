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

void rev(queue<int> &q)
{
    // Base case
    if (q.empty())
    {
        return;
    }

    // Recursive steps
    int element = q.front();
    q.pop();
    rev(q);
    q.push(element);
}

class q_stack_2
{
private:
    queue<int> q;

public:
    void push(int data)
    {
        q.push(data);
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        else
        {
            rev(q);
            cout << "Poping element : " << q.front() << endl;
            q.pop();
            rev(q);
            return;
        }
    }

    bool is_empty()
    {
        return q.empty();
    }

    int top()
    {
        if (q.empty())
        {
            return -1;
        }
        else
        {
            return q.back();
        }
    }
};

class q_stack_1
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int data)
    {
        q2.push(data);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Satck is empty" << endl;
            return;
        }

        cout << "poping element : " << q1.front() << endl;
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
        {
            return -1;
        }

        return q1.front();
    }

    bool is_empty()
    {
        return q1.empty();
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    q_stack_2 s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    cout << "top : " << s1.top() << endl;

    s1.pop();

    cout << "top : " << s1.top() << endl;
    s1.pop();
    s1.pop();
    s1.pop();
    cout << "top : " << s1.top() << endl;

    if (s1.is_empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Satck is not empty" << endl;
    }

    return 0;
}