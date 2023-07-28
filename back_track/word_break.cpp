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

void solve(int n, unordered_map<string, bool> dict, int ind1, int ind2, vector<string> &ans, string out, string &s)
{
    // Base case
    if (ind2 >= s.length())
    {
        ans.push_back(out);
        return;
    }

    // Recursive steps
    int l = ind2 - ind1 + 1;

    if (dict[s.substr(ind1, l)])
    {
        for (int i = ind1; i <= ind2; i++)
        {
            out.push_back(s[i]);
        }
        out.push_back(' ');
        solve(n, dict, ind2 + 1, ind2 + 1, ans, out, s);
        for (int i = 0; i <= l; i++)
        {
            out.pop_back();
        }
    }
    else
    {
        solve(n, dict, ind1, ind2 + 1, ans, out, s);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    unordered_map<string, bool> dict;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        dict[s] = 1;
    }

    vector<string> ans;
    string input;

    cin >> input;

    string out = "";

    solve(n, dict, 0, 0, ans, out, input);

    for (auto it : ans)
    {
        cout << it << endl;
    }

    return 0;
}