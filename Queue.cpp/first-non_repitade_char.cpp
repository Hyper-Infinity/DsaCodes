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

string solve(string &s)
{
    string ans = "";
    unordered_map<char, int> m(26);
    int size = s.size();

    deque<char> dq;

    for (int i = 0; i < size; i++)
    {
        int element = s[i];
        m[element]++;
        dq.push_back(element);

        while (!dq.empty())
        {
            if (m[dq.front()] > 1)
            {
                dq.pop_front();
            }
            else
            {
                ans.push_back(dq.front());
                break;
            }
        }
        if (dq.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    string ans;

    ans = solve(s);

    cout << ans << endl;

    return 0;
}