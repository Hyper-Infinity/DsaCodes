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

//  <<<<<<<<<<<  O(1) space and time comp >>>>>>>>>>>  // 
class SpecialStack_1
{
    // Define the data members.
    stack<int> s;
    int mini = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
public:
    void push(int data)
    {
        // for first element
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {
                s.push(2 * data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    int pop()
    {
        if (s.empty())
        {
            return -1;
        }

        int curr = s.top();
        s.pop();
        if (curr > mini)
        {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top()
    {
        if (s.empty())
            return -1;

        int curr = s.top();
        if (curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty()
    {
        return s.empty();
    }

    int getMin()
    {
        if (s.empty())
            return -1;

        return mini;
    }
};

//  <<<<<<<<<<<  O(1) time and O(n) space comp >>>>>>>>>>>  // 
class SpecialStack_2
{
    // Define the data members.
    stack<int> input_stack;
    stack<int> min_stack;
    int curr_min = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/

public:

    void push(int data)
    {
        input_stack.push(data);
        if (curr_min > data)
        {
            min_stack.push(data);
            curr_min = data;
        }
        else
        {
            min_stack.push(curr_min);
        }
    }

    void pop()
    {
        input_stack.pop();
        min_stack.pop();
    }

    int top()
    {
        return input_stack.top();
    }

    bool empty()
    {
        return input_stack.empty();
    }

    int min()
    {
        return min_stack.top();
    }

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SpecialStack_1 s1;
    s1.push(5);
    s1.push(3);
    s1.push(4);
    s1.push(6);
    s1.push(2);
    cout << "min element form s1 is : " << s1.getMin() << endl;

    SpecialStack_2 s2;
    s2.push(5);
    s2.push(3);
    s2.push(4);
    s2.push(6);
    s2.push(2);
    cout << "min element form s2 is : " << s2.min() << endl;

    return 0;
}