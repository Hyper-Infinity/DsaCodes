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

bool is_op(char c)
{
    if ((c == '-') || (c == '+') || (c == '*') || (c == '/'))
        return true;
    else
        return false;
}

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if ((is_op(s[i])) || (s[i] == '('))
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.top() == '(' || st.empty())
            {
                return false;
            }
            else
            {
                while (st.top() != '(')
                {
                    st.pop();
                }
                st.pop();
            }
        }
        else
        {
            continue;
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        if (findRedundantBrackets(s))
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }

    return 0;
}